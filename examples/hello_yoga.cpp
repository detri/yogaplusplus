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
    root.calculateLayout(SCREEN_WIDTH, SCREEN_HEIGHT);
    std::cout << "Layout width: " << root.getWidth() << '\n';
    std::cout << "Layout height: " << root.getHeight() << '\n';
    return 0;
}
