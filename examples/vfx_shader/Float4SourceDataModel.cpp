#include "Float4SourceDataModel.h"

#include "Float4Data.h"

unsigned Float4SourceDataModel::nPorts(PortType portType) const
{
    unsigned int result = 1;

    switch (portType)
    {
    case PortType::In:
        result = 4;
        break;

    case PortType::Out:
        result = 1;

    default:
        break;
    }

    return result;
}

QString Float4SourceDataModel::portCaption(PortType portType, PortIndex portIndex) const
{
    if (portType == PortType::Out)
    {
        return QStringLiteral("XYZW");
    }

    switch (portIndex)
    {
    case 0:
        return QStringLiteral("X");

    case 1:
        return QStringLiteral("Y");

    case 2:
        return QStringLiteral("Z");

    case 3:
        return QStringLiteral("W");

    default:
        break;
    }

    return QStringLiteral("");
}


NodeDataType Float4SourceDataModel::dataType(PortType portType, PortIndex portIndex) const
{
    NodeDataType result = TextData().type();

    switch (portType)
    {
    case PortType::In:
        result = FloatData().type();
        break;

    case PortType::Out:
        result = Float4Data().type();
        break;

    default:
        break;
    }

    return result;
}

void Float4SourceDataModel::setInData(std::shared_ptr<NodeData> data, int portIndex)
{
    const auto numberData = std::dynamic_pointer_cast<FloatData>(data);

    switch (portIndex)
    {
    case 0:
        _x = numberData;
        break;

    case 1:
        _y = numberData;
        break;

    case 2:
        _z = numberData;
        break;

    case 3:
        _w = numberData;
        break;

    default:
        break;
    }

    emit(dataUpdated(0));
}


std::shared_ptr<NodeData> Float4SourceDataModel::outData(PortIndex port)
{
    return std::make_shared<Float4Data>(
        _x,
        _y,
        _z,
        _w
    );
}


