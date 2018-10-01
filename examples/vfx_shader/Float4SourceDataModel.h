#pragma once

#include <QtCore/QObject>
#include "FloatData.h"
#include "TextData.h"
#include <nodes/NodeDataModel>

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataModel;

class Float4SourceDataModel : public NodeDataModel
{
    Q_OBJECT

public:
    Float4SourceDataModel() = default;
    virtual ~Float4SourceDataModel() = default;

    QString caption() const override
    {
        return QString("Float4");
    }

    bool captionVisible() const override
    {
        return false;
    }

    QString portCaption(PortType portType, PortIndex portIndex) const override;

    static QString Name()
    {
        return QString("Float4SourceDataModel");
    }

    bool portCaptionVisible(PortType, PortIndex) const override
    {
        return true;
    }

    QString name() const override
    {
        return Float4SourceDataModel::Name();
    }

    unsigned int nPorts(PortType portType) const override;
    NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

    QWidget* embeddedWidget() override
    {
        return nullptr;
    }

    std::shared_ptr<NodeData> outData(PortIndex port) override;

    void setInData(std::shared_ptr<NodeData> data, int portIndex) override;

private:
    std::shared_ptr<FloatData> _x =
        std::make_shared<FloatData>(FloatData(0.0f));
    std::shared_ptr<FloatData> _y =
        std::make_shared<FloatData>(FloatData(0.0f));
    std::shared_ptr<FloatData> _z =
        std::make_shared<FloatData>(FloatData(0.0f));
    std::shared_ptr<FloatData> _w =
        std::make_shared<FloatData>(FloatData(1.0f));
};