#pragma once

#include "FloatData.h"

#include <nodes/NodeDataModel>

using QtNodes::NodeDataType;
using QtNodes::NodeData;

class Float4Data : public NodeData
{
public:
    Float4Data() = default;

    Float4Data(
        const std::shared_ptr<FloatData> x,
        const std::shared_ptr<FloatData> y,
        const std::shared_ptr<FloatData> z,
        const std::shared_ptr<FloatData> w
    )
        : _x(x)
        , _y(y)
        , _z(z)
        , _w(w)
    {
        
    }

    NodeDataType type() const override
    {
        return NodeDataType{ "float4", "Float4" };
    }

    std::shared_ptr<FloatData> X() const
    {
        return _x;
    }

    std::shared_ptr<FloatData> Y() const
    {
        return _y;
    }

    std::shared_ptr<FloatData> Z() const
    {
        return _z;
    }

    std::shared_ptr<FloatData> W() const
    {
        return _w;
    }

    QString Float4ToString() const
    {
        return QString("FLOAT4(" +
            _x->numberAsText() + "," +
            _y->numberAsText() + "," +
            _z->numberAsText() + "," +
            _w->numberAsText() + ")");
    }

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