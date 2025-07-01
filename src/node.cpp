#include "yogaplusplus/node.hpp"

namespace Yoga
{
    Node::Node() : _yogaNode{YGNodeNew()}
    {
    }

    Node::~Node()
    {
        YGNodeFree(_yogaNode);
    }

    void Node::calculateLayout(const float width, const float height, const YGDirection direction)
    {
        YGNodeCalculateLayout(_yogaNode, width, height, direction);
    }

    void Node::setX(const float x)
    {
        YGNodeStyleSetPosition(_yogaNode, YGEdgeLeft, x);
    }

    void Node::setY(const float y)
    {
        YGNodeStyleSetPosition(_yogaNode, YGEdgeTop, y);
    }

    void Node::setPosition(const float x, const float y)
    {
        setX(x);
        setY(y);
    }

    void Node::setWidth(const float width)
    {
        YGNodeStyleSetWidth(_yogaNode, width);
    }

    void Node::setHeight(const float height)
    {
        YGNodeStyleSetHeight(_yogaNode, height);
    }

    void Node::setSize(const float width, const float height)
    {
        setWidth(width);
        setHeight(height);
    }

    void Node::setWidthPercent(const float widthPercent)
    {
        YGNodeStyleSetWidthPercent(_yogaNode, widthPercent);
    }

    void Node::setHeightPercent(const float heightPercent)
    {
        YGNodeStyleSetHeightPercent(_yogaNode, heightPercent);
    }

    void Node::setSizePercent(const float widthPercent, const float heightPercent)
    {
        setWidthPercent(widthPercent);
        setHeightPercent(heightPercent);
    }

    void Node::setFlex(const float flex)
    {
        YGNodeStyleSetFlex(_yogaNode, flex);
    }

    void Node::setFlexGrow(const float flexGrow)
    {
        YGNodeStyleSetFlexGrow(_yogaNode, flexGrow);
    }

    void Node::setFlexShrink(const float flexShrink)
    {
        YGNodeStyleSetFlexShrink(_yogaNode, flexShrink);
    }

    void Node::setFlexBasis(const float flexBasis)
    {
        YGNodeStyleSetFlexBasis(_yogaNode, flexBasis);
    }

    void Node::setFlexDirection(const YGFlexDirection flexDirection)
    {
        YGNodeStyleSetFlexDirection(_yogaNode, flexDirection);
    }

    float Node::getLeft() const
    {
        return YGNodeLayoutGetLeft(_yogaNode);
    }

    float Node::getTop() const
    {
        return YGNodeLayoutGetTop(_yogaNode);
    }

    float Node::getRight() const
    {
        return YGNodeLayoutGetRight(_yogaNode);
    }

    float Node::getBottom() const
    {
        return YGNodeLayoutGetBottom(_yogaNode);
    }

    float Node::getWidth() const
    {
        return YGNodeLayoutGetWidth(_yogaNode);
    }

    float Node::getHeight() const
    {
        return YGNodeLayoutGetHeight(_yogaNode);
    }

    size_t Node::getChildCount() const
    {
        return YGNodeGetChildCount(_yogaNode);
    }

    void Node::insertChild(const Node& child)
    {
        YGNodeInsertChild(_yogaNode, child._yogaNode, getChildCount());
    }

    void Node::removeChild(const Node& child)
    {
        YGNodeRemoveChild(_yogaNode, child._yogaNode);
    }

    YGDisplay Node::getDisplay() const
    {
        return YGNodeStyleGetDisplay(_yogaNode);
    }

    void Node::setDisplay(const YGDisplay display)
    {
        return YGNodeStyleSetDisplay(_yogaNode, display);
    }
}
