#include "yogaplusplus/node.hpp"

namespace Yoga
{
    BaseNode::BaseNode() : _yogaNode{nullptr}
    {
    }

    BaseNode::~BaseNode()
    = default;

    void BaseNode::calculateLayout(const float width, const float height, const YGDirection direction)
    {
        YGNodeCalculateLayout(_yogaNode, width, height, direction);
    }

    void BaseNode::setX(const float x)
    {
        YGNodeStyleSetPosition(_yogaNode, YGEdgeLeft, x);
    }

    void BaseNode::setY(const float y)
    {
        YGNodeStyleSetPosition(_yogaNode, YGEdgeTop, y);
    }

    void BaseNode::setPosition(const float x, const float y)
    {
        setX(x);
        setY(y);
    }

    void BaseNode::setWidth(const float width)
    {
        YGNodeStyleSetWidth(_yogaNode, width);
    }

    void BaseNode::setHeight(const float height)
    {
        YGNodeStyleSetHeight(_yogaNode, height);
    }

    void BaseNode::setSize(const float width, const float height)
    {
        setWidth(width);
        setHeight(height);
    }

    void BaseNode::setWidthPercent(const float widthPercent)
    {
        YGNodeStyleSetWidthPercent(_yogaNode, widthPercent);
    }

    void BaseNode::setHeightPercent(const float heightPercent)
    {
        YGNodeStyleSetHeightPercent(_yogaNode, heightPercent);
    }

    void BaseNode::setSizePercent(const float widthPercent, const float heightPercent)
    {
        setWidthPercent(widthPercent);
        setHeightPercent(heightPercent);
    }

    void BaseNode::setFlex(const float flex)
    {
        YGNodeStyleSetFlex(_yogaNode, flex);
    }

    void BaseNode::setFlexGrow(const float flexGrow)
    {
        YGNodeStyleSetFlexGrow(_yogaNode, flexGrow);
    }

    void BaseNode::setFlexShrink(const float flexShrink)
    {
        YGNodeStyleSetFlexShrink(_yogaNode, flexShrink);
    }

    void BaseNode::setFlexBasis(const float flexBasis)
    {
        YGNodeStyleSetFlexBasis(_yogaNode, flexBasis);
    }

    void BaseNode::setFlexDirection(const YGFlexDirection flexDirection)
    {
        YGNodeStyleSetFlexDirection(_yogaNode, flexDirection);
    }

    void BaseNode::setMargin(const float margin)
    {
        YGNodeStyleSetMargin(_yogaNode, YGEdgeAll, margin);
    }

    void BaseNode::setMargin(const float marginTop, const float marginRight, const float marginBottom, const float marginLeft)
    {
        YGNodeStyleSetMargin(_yogaNode, YGEdgeTop, marginTop);
        YGNodeStyleSetMargin(_yogaNode, YGEdgeRight, marginRight);
        YGNodeStyleSetMargin(_yogaNode, YGEdgeBottom, marginBottom);
        YGNodeStyleSetMargin(_yogaNode, YGEdgeLeft, marginLeft);
    }

    void BaseNode::setPadding(const float padding)
    {
        YGNodeStyleSetPadding(_yogaNode, YGEdgeAll, padding);
    }

    void BaseNode::setPadding(const float paddingTop, const float paddingRight, const float paddingBottom, const float paddingLeft)
    {
        YGNodeStyleSetPadding(_yogaNode, YGEdgeTop, paddingTop);
        YGNodeStyleSetPadding(_yogaNode, YGEdgeRight, paddingRight);
        YGNodeStyleSetPadding(_yogaNode, YGEdgeBottom, paddingBottom);
        YGNodeStyleSetPadding(_yogaNode, YGEdgeLeft, paddingLeft);
    }

    void BaseNode::setContext(void* contextPtr)
    {
        YGNodeSetContext(_yogaNode, contextPtr);
    }

    size_t BaseNode::childCount() const
    {
        return YGNodeGetChildCount(_yogaNode);
    }

    float BaseNode::getLeft() const
    {
        return YGNodeLayoutGetLeft(_yogaNode);
    }

    float BaseNode::getTop() const
    {
        return YGNodeLayoutGetTop(_yogaNode);
    }

    float BaseNode::getRight() const
    {
        return YGNodeLayoutGetRight(_yogaNode);
    }

    float BaseNode::getBottom() const
    {
        return YGNodeLayoutGetBottom(_yogaNode);
    }

    float BaseNode::getWidth() const
    {
        return YGNodeLayoutGetWidth(_yogaNode);
    }

    float BaseNode::getHeight() const
    {
        return YGNodeLayoutGetHeight(_yogaNode);
    }

    size_t BaseNode::getChildCount() const
    {
        return YGNodeGetChildCount(_yogaNode);
    }

    void BaseNode::insertChild(const Node& child)
    {
        YGNodeInsertChild(_yogaNode, child._yogaNode, getChildCount());
    }

    void BaseNode::removeChild(const Node& child)
    {
        YGNodeRemoveChild(_yogaNode, child._yogaNode);
    }

    void BaseNode::insertChild(const WeakNode& child)
    {
        YGNodeInsertChild(_yogaNode, child._yogaNode, getChildCount());
    }

    void BaseNode::removeChild(const WeakNode& child)
    {
        YGNodeRemoveChild(_yogaNode, child._yogaNode);
    }

    YGDisplay BaseNode::getDisplay() const
    {
        return YGNodeStyleGetDisplay(_yogaNode);
    }

    void BaseNode::setDisplay(const YGDisplay display)
    {
        return YGNodeStyleSetDisplay(_yogaNode, display);
    }

    bool BaseNode::hasChildren() const
    {
        return YGNodeGetChildCount(_yogaNode) > 0;
    }

    void BaseNode::getChildren(std::vector<WeakNode>& children) const
    {
        const size_t count = YGNodeGetChildCount(_yogaNode);
        children.clear();
        children.reserve(count);

        for (size_t i = 0; i < count; ++i) {
            YGNodeRef childNode = YGNodeGetChild(_yogaNode, i);
            children.emplace_back(childNode);
        }
    }

    std::vector<WeakNode> BaseNode::getChildren() const
    {
        std::vector<WeakNode> children;
        children.reserve(childCount());

        for (size_t i = 0; i < childCount(); ++i) {
            children.emplace_back(YGNodeGetChild(_yogaNode, i));
        }

        return children;
    }

    Node::Node(YGNodeRef yogaNode)
    {
        _yogaNode = yogaNode;
    }

    Node::~Node()
    {
        YGNodeFree(_yogaNode);
    }

    WeakNode Node::weak() const
    {
        return WeakNode{_yogaNode};
    }

    WeakNode::WeakNode(YGNodeRef yogaNode)
    {
        _yogaNode = yogaNode;
    }
}
