#include "ShaderOutDataModel.h"

#include <QFile>

unsigned ShaderOutDataModel::nPorts(PortType portType) const
{
    unsigned int result = 1;

    switch (portType)
    {
    case PortType::In:
        result = 1;
        break;

    case PortType::Out:
        result = 0;
        break;

    default:
        break;
    }

    return result;
}

QString ShaderOutDataModel::portCaption(PortType portType, PortIndex portIndex) const
{
    QString caption = "";

    if (portType == PortType::In)
    {
        switch (portIndex)
        {
        case 0:
            return "Emissive";

        default:
            break;
        }
    }

    return caption;
}


NodeDataType ShaderOutDataModel::dataType(PortType portType, PortIndex portIndex) const
{
    auto dataType = Float4Data().type();

    if (portType == PortType::In)
    {
        switch (portIndex)
        {
        case 0:
            break;

        default:
            break;
        }
    }

    return dataType;
}

std::shared_ptr<NodeData> ShaderOutDataModel::outData(PortIndex port)
{
    std::shared_ptr<NodeData> dummy;
    return dummy;
}

void ShaderOutDataModel::setInData(std::shared_ptr<NodeData> nodeData, PortIndex port)
{
    Q_UNUSED(port);

    const auto float4Data = std::dynamic_pointer_cast<Float4Data>(nodeData);

    if (!float4Data)
    {
        return;
    }

    _emissiveInput = float4Data;

    SaveShader();
}

void ShaderOutDataModel::SaveShader() const
{
    const QString filePath = "D:\\dev\\sisdk\\3.0\\Sample\\VFX\\Test\\test.fxh";
    const QString result = _shaderText + _emissiveInput->Float4ToString() + ";\n}";
    QFile file(filePath);

    if (file.open(QFile::WriteOnly))
    {
        qDebug(QString("Error opening file for write: " + file.errorString()).toStdString().c_str());
        return;
    }

    file.write(result.toStdString().c_str());
    file.resize(file.pos()); // clear the previous file contents
}



