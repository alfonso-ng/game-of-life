cmake_minimum_required(VERSION 3.28)
project(GameOfLife)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(X11 REQUIRED)

add_executable(GameOfLife
    src/main.cpp
    src/Game.cpp
    src/Grid.cpp
    src/Matrix.cpp
    src/Vec2List.cpp
    src/Renderer.cpp
)
target_compile_features(GameOfLife PRIVATE cxx_std_17)
target_link_libraries(GameOfLife PRIVATE X11::X11)
target_include_directories(GameOfLife PRIVATE include)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT GameOfLife)
