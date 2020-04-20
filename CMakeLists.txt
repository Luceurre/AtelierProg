CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
add_definitions(-std=c++11)
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
PROJECT(AtelierProg)

FIND_PACKAGE(SDL2 REQUIRED)
FIND_PACKAGE(SDL2_image REQUIRED)
INCLUDE(FindPkgConfig REQUIRED)

pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)

include_directories(${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_DIRS})

link_directories (${SDL2_LIBRARY_DIRS}
        ${SDL2_IMAGE_LIBRARY_DIRS})

add_executable(PierreSandbox main_pierre.cpp API/Logger.cpp API/Logger.h API/Scene.cpp API/Scene.h API/SceneView.cpp API/SceneView.h API/SceneLogic.cpp API/SceneLogic.h Tests/SceneConsole.cpp Tests/SceneConsole.h)
add_executable(JulienSandbox main_julien.cpp Windows/Game.cpp Windows/Game.h Windows/TextureManager.h Windows/TextureManager.cpp Windows/GameObject.h Windows/GameObject.cpp Windows/Map.h Windows/Map.cpp Windows/ECS/ECS.h Windows/ECS/Components.h Windows/ECS/SpriteComponent.h Windows/ECS/TransformComponent.h Windows/Vector2D.h Windows/Vector2D.cpp Windows/ECS/KeyboardController.h Windows/Collision.cpp Windows/Collision.h)

target_link_libraries (PierreSandbox ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES})
target_link_libraries (JulienSandbox ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES})