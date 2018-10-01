#include "TextDisplayDataModel.h"

TextDisplayDataModel::TextDisplayDataModel()
    : _label(new QLabel("Resulting text"))
{
    _label->setMargin(3);
}

unsigned TextDisplayDataModel::nPorts(PortType portType) const
{
    unsigned int result = 1;

    switch (portType)
    {
    case PortType::In:
        result = 1;
        break;

    case PortType::Out:
        result = 0;

    default:
        break;
    }

    return result;
}

NodeDataType TextDisplayDataModel::dataType(PortType portType, PortIndex portIndex) const
{
    return TextData().type();
}

std::shared_ptr<NodeData> TextDisplayDataModel::outData(PortIndex port)
{
    std::shared_ptr<NodeData> ptr;
    return ptr;
}

void TextDisplayDataModel::setInData(const std::shared_ptr<NodeData> data, int)
{
    const auto textData = std::dynamic_pointer_cast<TextData>(data);

    if (textData)
    {
        const auto innerText = textData->text();
        _label->setText(innerText);

        SaveShader();
    }
    else
    {
        _label->clear();
    }

    _label->adjustSize();
}

void TextDisplayDataModel::SaveShader() const
{
    std::string result = (_shaderText + " " + _label->text() + "\n}\n").toStdString();
    printf(result.c_str());
}
