#pragma once

#include <QtCore/qobject.h>
#include <QtWidgets/qlabel.h>

#include <nodes/NodeDataModel>

#include <iostream>

#include "TextData.h"

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataModel;

class TextDisplayDataModel : public NodeDataModel
{
    Q_OBJECT

public:
    TextDisplayDataModel();
    virtual ~TextDisplayDataModel() {}

    QString caption() const override
    {
        return QString("Text display");
    }

    bool captionVisible() const override
    {
        return false;
    }

    static QString Name()
    {
        return QString("TextDisplayDataModel");
    }

    QString name() const override
    {
        return TextDisplayDataModel::Name();
    }

    unsigned int nPorts(PortType portType) const override;

    NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

    std::shared_ptr<NodeData> outData(PortIndex port) override;

    void setInData(const std::shared_ptr<NodeData> data, int) override;

    QWidget* embeddedWidget() override { return _label; }

private:
    void SaveShader() const;

    QLabel* _label;
    QString _shaderText = R"%(

#define VFX_VERSION 2

void PixelShader(INOUT ParticleSurfaceData particleSurfaceData)
{
    particleSurfaceData.emissive = 
    )%";
};