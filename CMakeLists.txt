CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
SET(CMAKE_CXX_FLAGS -pthread)
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
SET(CMAKE_CXX_STANDARD 20)

PROJECT(AtelierProg)

FIND_PACKAGE(SDL2 REQUIRED)
FIND_PACKAGE(SDL2_image REQUIRED)
INCLUDE(FindPkgConfig REQUIRED)

pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)
pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)

include_directories(${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_DIRS})

link_directories (${SDL2_LIBRARY_DIRS}
        ${SDL2_IMAGE_LIBRARY_DIRS})

# On récupère tous les fichiers .cpp et .h
SET(PIERRE_SRC_DIR API)
SET(PIERRE_SRC ${PIERRE_SRC_DIR}/Console.h ${PIERRE_SRC_DIR}/Console.cpp ${PIERRE_SRC_DIR}/Game.cpp ${PIERRE_SRC_DIR}/Game.h ${PIERRE_SRC_DIR}/Logger.cpp ${PIERRE_SRC_DIR}/Logger.h ${PIERRE_SRC_DIR}/Scene.cpp ${PIERRE_SRC_DIR}/Scene.h ${PIERRE_SRC_DIR}/SceneLogic.h ${PIERRE_SRC_DIR}/SceneLogic.cpp ${PIERRE_SRC_DIR}/SceneManager.cpp ${PIERRE_SRC_DIR}/SceneManager.h ${PIERRE_SRC_DIR}/SceneView.cpp ${PIERRE_SRC_DIR}/SceneView.h ${PIERRE_SRC_DIR}/tools.cpp ${PIERRE_SRC_DIR}/tools.h ${PIERRE_SRC_DIR}/Window.cpp ${PIERRE_SRC_DIR}/Window.h ${PIERRE_SRC_DIR}/WindowManager.cpp ${PIERRE_SRC_DIR}/WindowManager.h API/MouseHandler.cpp API/MouseHandler.h)
SET(PIERRE_TEST_DIR Tests)
SET(PIERRE_TEST_SRC ${PIERRE_TEST_DIR}/SceneConsole.cpp ${PIERRE_TEST_DIR}/SceneConsole.h Tests/SceneMenu.cpp Tests/SceneMenu.h)

# De même pour Julien
SET(JULIEN_SRC_DIR Windows)
SET(JULIEN_ECS_DIR ECS)
SET(JULIEN_SRC ${JULIEN_SRC_DIR}/Collision.cpp ${JULIEN_SRC_DIR}/Collision.h ${JULIEN_SRC_DIR}/Game.cpp ${JULIEN_SRC_DIR}/Game.h ${JULIEN_SRC_DIR}/Map.cpp ${JULIEN_SRC_DIR}/Map.h ${JULIEN_SRC_DIR}/TextureManager.h ${JULIEN_SRC_DIR}/TextureManager.cpp ${JULIEN_SRC_DIR}/Vector2D.cpp ${JULIEN_SRC_DIR}/Vector2D.h)
SET(JULIEN_ECS_SRC ${JULIEN_SRC_DIR}/${JULIEN_ECS_DIR}/Animation.h ${JULIEN_SRC_DIR}/${JULIEN_ECS_DIR}/ColliderComponent.h ${JULIEN_SRC_DIR}/${JULIEN_ECS_DIR}/Components.h ${JULIEN_SRC_DIR}/${JULIEN_ECS_DIR}/ECS.cpp ${JULIEN_SRC_DIR}/${JULIEN_ECS_DIR}/ECS.h ${JULIEN_SRC_DIR}/${JULIEN_ECS_DIR}/MouseComponent.h ${JULIEN_SRC_DIR}/${JULIEN_ECS_DIR}/KeyboardController.h ${JULIEN_SRC_DIR}/${JULIEN_ECS_DIR}/SpriteComponent.h ${JULIEN_SRC_DIR}/${JULIEN_ECS_DIR}/TileComponent.h ${JULIEN_SRC_DIR}/${JULIEN_ECS_DIR}/TransformComponent.h Windows/ECS/ClickableComponent.h)

add_executable(PierreSandbox main_pierre.cpp ${PIERRE_SRC} ${PIERRE_TEST_SRC}  ${JULIEN_ECS_SRC} ${JULIEN_SRC})
# add_executable(JulienSandbox main_julien.cpp Windows/Game.cpp Windows/Game.h Windows/TextureManager.h Windows/TextureManager.cpp Windows/GameObject.h Windows/GameObject.cpp Windows/Map.h Windows/Map.cpp Windows/ECS/ECS.h Windows/ECS/Components.h Windows/ECS/SpriteComponent.h Windows/ECS/TransformComponent.h Windows/Vector2D.h Windows/Vector2D.cpp Windows/ECS/KeyboardController.h Windows/Collision.h Windows/Collision.cpp Windows/ECS/ECS.cpp Windows/ECS/Animation.h Windows/ECS/MouseComponent.h)
add_executable(JulienSandbox main_julien.cpp ${JULIEN_SRC} ${JULIEN_ECS_SRC})

add_executable(MathisSandbox main_mathis.cpp options/parser.cpp options/parser.h options/options.cpp options/options.h API/Logger.cpp API/Logger.h)
add_executable(PierreMathisSandbox PierreMathis/main_pierremathis.cpp Windows/ECS/MouseComponent.h)

target_link_libraries (MathisSandbox ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})
target_link_libraries (PierreSandbox ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})
target_link_libraries (JulienSandbox ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})