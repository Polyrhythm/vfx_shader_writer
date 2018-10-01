#pragma once

#include <nodes/NodeDataModel>

using QtNodes::NodeDataType;
using QtNodes::NodeData;

class FloatData : public NodeData
{
public:
    FloatData() {}

    FloatData(const float number)
        : _number(number)
    {}

    NodeDataType type() const override
    {
        return NodeDataType{ "float" "Float" };
    }

    float number() const
    {
        return _number;
    }

    QString numberAsText() const
    {
        return QString::number(_number, 'f');
    }

    void SetNumber(const float number)
    {
        _number = number;
    }

private:
    float _number = 0.0f;
};