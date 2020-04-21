CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
SET(CMAKE_CXX_FLAGS -pthread)
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

add_executable(PierreSandbox main_pierre.cpp API/Logger.cpp API/Logger.h API/Scene.cpp API/Scene.h API/SceneView.cpp API/SceneView.h API/SceneLogic.cpp API/SceneLogic.h Tests/SceneConsole.cpp Tests/SceneConsole.h API/Window.cpp API/Window.h API/WindowManager.cpp API/WindowManager.h Sandbox/A.cpp Sandbox/A.h Sandbox/AManager.cpp Sandbox/AManager.h API/SceneManager.cpp API/SceneManager.h API/Console.cpp API/Console.h)
add_executable(JulienSandbox main_julien.cpp Windows/Game.cpp Windows/Game.h Windows/TextureManager.h Windows/TextureManager.cpp Windows/GameObject.h Windows/GameObject.cpp Windows/Map.h Windows/Map.cpp Windows/ECS/ECS.h Windows/ECS/Components.h Windows/ECS/SpriteComponent.h Windows/ECS/TransformComponent.h Windows/Vector2D.h Windows/Vector2D.cpp Windows/ECS/KeyboardController.h Windows/Collision.h Windows/Collision.cpp)
add_executable(MathisSandbox main_mathis.cpp options/parser.cpp options/parser.h)

target_link_libraries (MathisSandbox ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES})
target_link_libraries (PierreSandbox ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES})
target_link_libraries (JulienSandbox ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES})