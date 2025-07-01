# Yoga Plus Plus
Notice: This library is for personal use and is not feature-complete. It will be updated as I need new features from Yoga.

This library provides extremely thin RAII wrappers over the [Yoga layout engine](https://github.com/facebook/yoga) by Meta (previously Facebook).

The intention of this library is only to allow Yoga objects to be treated as C++ objects.
It does not manage node relationships automatically, and it does not
ensure lifetimes are valid. That is still up to the user.

### Usage

Add it via CMake:
```cmake
FetchContent_Declare(
        yogaplusplus
        GIT_REPOSITORY https://github.com/detri/yogaplusplus
        GIT_TAG main
)
FetchContent_MakeAvailable(yogaplusplus)

add_executable(myTarget)
target_link_libraries(myTarget PRIVATE yogaplusplus)
```

Basic example: `examples/hello_yoga.cpp`
```c++
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
```