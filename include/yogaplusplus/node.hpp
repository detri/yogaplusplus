#ifndef YOGA_NODE_HPP
#define YOGA_NODE_HPP

#include <vector>
#include <yoga/Yoga.h>

namespace Yoga
{
    class BaseNode
    {
    protected:
        YGNodeRef _yogaNode;

    public:
        explicit BaseNode();

        virtual ~BaseNode();

        friend class LayoutContext;

        void setX(float x);

        void setY(float y);

        void setPosition(float x, float y);

        void setWidth(float width);

        void setHeight(float height);

        void setSize(float width, float height);

        void setWidthPercent(float widthPercent);

        void setHeightPercent(float heightPercent);

        void setSizePercent(float widthPercent, float heightPercent);

        void setFlex(float flex);

        void setFlexGrow(float flexGrow);

        void setFlexShrink(float flexShrink);

        void setFlexBasis(float flexBasis);

        void setFlexDirection(YGFlexDirection flexDirection);

        void setMargin(float margin);

        void setMargin(float marginTop, float marginRight, float marginBottom, float marginLeft);

        void setPadding(float padding);

        void setPadding(float paddingTop, float paddingRight, float paddingBottom, float paddingLeft);

        void setContext(void* contextPtr);

        [[nodiscard]] size_t childCount() const;

        template<typename Context>
        auto* getContext() const
        {
            return static_cast<Context*>(YGNodeGetContext(_yogaNode));
        }

        [[nodiscard]] bool hasChildren() const;

        [[nodiscard]] float getLeft() const;

        [[nodiscard]] float getTop() const;

        [[nodiscard]] float getRight() const;

        [[nodiscard]] float getBottom() const;

        [[nodiscard]] float getWidth() const;

        [[nodiscard]] float getHeight() const;

        [[nodiscard]] size_t getChildCount() const;

        void insertChild(const class Node& child);

        void removeChild(const Node& child);

        void insertChild(const class WeakNode& child);

        void removeChild(const WeakNode& child);

        void getChildren(std::vector<WeakNode>& children) const;

        [[nodiscard]] std::vector<WeakNode> getChildren() const;

        [[nodiscard]] WeakNode getParent() const;

        [[nodiscard]] YGDisplay getDisplay() const;

        void setDisplay(YGDisplay display);

        void calculateLayout(float width, float height, YGDirection direction = YGDirectionLTR);
    };

    class Node final : public BaseNode
    {
    public:
        explicit Node(YGNodeRef yogaNode = YGNodeNew());

        ~Node() override;

        [[nodiscard]] WeakNode weak() const;
    };

    class WeakNode final : public BaseNode
    {
    public:
        explicit WeakNode(YGNodeRef yogaNode);
    };
}

#endif //YOGA_NODE_HPP
