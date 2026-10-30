cmake_minimum_required(VERSION 3.28)
project(GameOfLife)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(GameOfLife
    src/main.cpp
    src/Game.cpp
    src/Grid.cpp
    src/Matrix.cpp
    src/Vec2List.cpp
)
target_compile_features(GameOfLife PRIVATE cxx_std_17)
target_link_libraries(GameOfLife PRIVATE SFML::Graphics)
target_include_directories(GameOfLife PRIVATE include)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT GameOfLife)
