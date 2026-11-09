cmake_minimum_required(VERSION 3.20)

project(2DGameEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

add_executable(GameEngine
    src/main.cpp
    src/Player.cpp
    src/Enemy.cpp
    src/Game.cpp
    src/GameObject.cpp
)

target_include_directories(GameEngine PRIVATE include)

target_link_libraries(GameEngine PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)