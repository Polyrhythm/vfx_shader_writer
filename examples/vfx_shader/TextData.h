#pragma once

#include <nodes/NodeDataModel>

using QtNodes::NodeData;
using QtNodes::NodeDataType;

class TextData : public NodeData
{
public:
    TextData() {}

    TextData(const QString& text)
        : _text(text)
    {}

    NodeDataType type() const override
    {
        return NodeDataType{ "text", "Text" };
    }

    QString text() const {
        return _text;
    }

private:
    QString _text;
};