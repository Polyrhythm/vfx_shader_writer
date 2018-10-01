#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QLineEdit>

#include "FloatData.h"

#include <nodes/NodeDataModel>

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataModel;

class FloatSourceDataModel : public NodeDataModel
{
    Q_OBJECT

public:
    FloatSourceDataModel();
    virtual ~FloatSourceDataModel() = default;

    QString caption() const override
    {
        return QString("Constant");
    }

    bool captionVisible() const override
    {
        return false;
    }

    static QString Name()
    {
        return QString("FloatSourceDataModel");
    }

    QString name() const override
    {
        return FloatSourceDataModel::Name();
    }

    unsigned int nPorts(PortType portType) const override;

    NodeDataType dataType(PortType portType, PortIndex portIndex) const override
    {
        return FloatData().type();
    }

    std::shared_ptr<NodeData> outData(PortIndex portIndex) override;

    void setInData(std::shared_ptr<NodeData> nodeData, PortIndex port) override
    {
        
    }

    QWidget* embeddedWidget() override
    {
        return _lineEdit;
    }

private slots:
    void onTextEdited(QString const& string);

private:
    std::shared_ptr<FloatData> _number =
        std::make_shared<FloatData>(FloatData(0.0f));

    QLineEdit* _lineEdit;
};