#ifndef YOGA_NODE_HPP
#define YOGA_NODE_HPP

#include <yoga/Yoga.h>

namespace Yoga
{
    class Node
    {

    public:
        explicit Node();

        ~Node();

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

        [[nodiscard]] float getLeft() const;

        [[nodiscard]] float getTop() const;

        [[nodiscard]] float getRight() const;

        [[nodiscard]] float getBottom() const;

        [[nodiscard]] float getWidth() const;

        [[nodiscard]] float getHeight() const;

        [[nodiscard]] size_t getChildCount() const;

        void insertChild(const Node& child);

        void removeChild(const Node& child);

        [[nodiscard]] YGDisplay getDisplay() const;

        void setDisplay(YGDisplay display);

        void calculateLayout(float width, float height, YGDirection direction = YGDirectionLTR);

    private:
        YGNodeRef _yogaNode;
    };
}

#endif //YOGA_NODE_HPP
