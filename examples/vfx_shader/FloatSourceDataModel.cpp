#include "FloatSourceDataModel.h"

#include <QtGui/QDoubleValidator>

FloatSourceDataModel::FloatSourceDataModel()
    : _lineEdit(new QLineEdit())
{
    _lineEdit->setValidator(new QDoubleValidator());
    _lineEdit->setMaximumSize(_lineEdit->sizeHint());

    connect(_lineEdit, &QLineEdit::textChanged,
        this, &FloatSourceDataModel::onTextEdited);

    _lineEdit->setText(_number->numberAsText());
}

unsigned FloatSourceDataModel::nPorts(PortType portType) const
{
    unsigned int result = 1;

    switch (portType)
    {
    case PortType::In:
        result = 0;
        break;

    case PortType::Out:
        result = 1;
        break;

    default:
        break;
    }

    return result;
}

void FloatSourceDataModel::onTextEdited(QString const& string)
{
    Q_UNUSED(string);

    bool isOk = false;

    float number = _lineEdit->text().toFloat(&isOk);

    if (isOk)
    {
        _number->SetNumber(number);
        emit dataUpdated(0);
        return;
    }

    emit dataInvalidated(0);
}

std::shared_ptr<NodeData> FloatSourceDataModel::outData(PortIndex portIndex)
{
    return _number;
}
