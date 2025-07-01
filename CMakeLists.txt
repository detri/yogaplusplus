cmake_minimum_required(VERSION 3.15)
project(yogaplusplus LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

set(YOGA_REPO https://github.com/facebook/yoga)
set(YOGA_TAG v3.2.1)

FetchContent_Declare(
        yoga
        GIT_REPOSITORY "${YOGA_REPO}"
        GIT_TAG "${YOGA_TAG}"
)

FetchContent_MakeAvailable(yoga)

add_library(yogaplusplus STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/yogaplusplus/yogaplusplus.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/node.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/config.cpp)
target_include_directories(yogaplusplus PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(yogaplusplus PUBLIC yogacore)

add_executable(hello_yoga examples/hello_yoga.cpp)
target_link_libraries(hello_yoga PRIVATE yogaplusplus)
