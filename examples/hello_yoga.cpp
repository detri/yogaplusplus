#include <yogaplusplus/yogaplusplus.hpp>
#include <iostream>

constexpr float SCREEN_WIDTH = 1280.f;
constexpr float SCREEN_HEIGHT = 720.f;

int main()
{
    Yoga::Config config;
    config.setPointScaleFactor(1.0f);
    Yoga::Node root;
    root.setWidthPercent(100.f);
    root.setHeightPercent(100.f);
    root.setFlexDirection(YGFlexDirectionColumn);

    Yoga::Node child1;
    child1.setFlex(1.f);
    child1.setFlexGrow(1.f);
    child1.setWidthPercent(100.f);
    child1.setHeightPercent(100.f);

    Yoga::Node child2;
    child2.setFlex(1.f);
    child2.setFlexGrow(1.f);
    child2.setWidthPercent(100.f);
    child2.setHeightPercent(100.f);

    root.insertChild(child1);
    root.insertChild(child2);

    root.calculateLayout(SCREEN_WIDTH, SCREEN_HEIGHT);

    std::cout << "Layout width: " << root.getWidth() << '\n';
    std::cout << "Layout height: " << root.getHeight() << '\n';

    std::cout << "Child 1 width: " << child1.getWidth() << '\n';
    std::cout << "Child 1 height: " << child1.getHeight() << '\n';
    std::cout << "Child 1 X: " << child1.getLeft() << '\n';
    std::cout << "Child 1 Y: " << child1.getTop() << '\n';

    std::cout << "Child 2 width: " << child2.getWidth() << '\n';
    std::cout << "Child 2 height: " << child2.getHeight() << '\n';
    std::cout << "Child 2 X: " << child2.getLeft() << '\n';
    std::cout << "Child 2 Y: " << child2.getTop() << '\n';
    return 0;
}
