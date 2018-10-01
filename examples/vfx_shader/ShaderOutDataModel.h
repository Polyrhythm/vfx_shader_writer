#pragma once

#include <QtCore/QObject>

#include "Float4Data.h"

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataModel;
using QtNodes::NodeDataType;

class ShaderOutDataModel : public NodeDataModel
{
    Q_OBJECT

public:
    ShaderOutDataModel() = default;
    virtual ~ShaderOutDataModel() = default;

    QString caption() const override
    {
        return QString("Shader out");
    }

    bool captionVisible() const override
    {
        return true;
    }

    static QString Name()
    {
        return QString("ShaderOutDataModel");
    }

    QString name() const override
    {
        return ShaderOutDataModel::Name();
    }

    QString portCaption(PortType portType, PortIndex portIndex) const override;

    bool portCaptionVisible(PortType, PortIndex) const override
    {
        return true;
    }

    unsigned int nPorts(PortType portType) const override;

    NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

    std::shared_ptr<NodeData> outData(PortIndex port) override;

    void setInData(std::shared_ptr<NodeData> nodeData, PortIndex port) override;

    QWidget* embeddedWidget() override
    {
        return nullptr;
    }

private:
    void SaveShader() const;

    std::shared_ptr<Float4Data> _emissiveInput =
        std::make_shared<Float4Data>(Float4Data());

    QString _shaderText = R"%(
// This key is required for the ShaderCacheServer, do not remove it
// #UGC_PBRCUSTOM_COMPUTE_TECHNIQUE_ID

#define VFX_VERSION 2

#define PS_MainSurface PixelShading

void PixelShading(INOUT PixelParticleData particleData)
{
    particleData.surfaceData = GetDefaultParticleSuefaceData();

    particleData.surfaceData.Emissive = 
    )%";
};