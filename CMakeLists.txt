CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
SET(CMAKE_CXX_STANDARD 20)
if(WIN32)

ELSE()
    SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
ENDIF()

PROJECT(AtelierProg)

IF(WIN32)
    INCLUDE_DIRECTORIES(include)
ELSE()
    FIND_PACKAGE(SDL2 REQUIRED)
    FIND_PACKAGE(SDL2_image REQUIRED)

    include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
ENDIF()

add_executable(PierreSandbox main_pierre.cpp API/Logger.cpp API/Logger.h API/Scene.cpp API/Scene.h API/SceneView.cpp API/SceneView.h API/SceneLogic.cpp API/SceneLogic.h Tests/SceneConsole.cpp Tests/SceneConsole.h)
add_executable(JulienSandbox main_julien.cpp Windows/Game.cpp Windows/Game.h Windows/TextureManager.h Windows/TextureManager.cpp Windows/GameObject.h Windows/GameObject.cpp Windows/Map.h Windows/Map.cpp Windows/ECS/ECS.h Windows/ECS/Components.h Windows/ECS/SpriteComponent.h Windows/ECS/TransformComponent.h Windows/Vector2D.h Windows/Vector2D.cpp Windows/ECS/KeyboardController.h)
add_executable(MathisSandbox main_mathis.cpp)

IF(WIN32)
    target_link_libraries(PierreSandbox bin)
    target_link_libraries(JulienSandbox bin)
    # target_link_libraries(PierreSandbox C:/Users/pglan/CLionProjects/AtelierProg/SDL2/lib/x86/SDL2.lib)
    # target_link_libraries(PierreSandbox C:/Users/pglan/CLionProjects/AtelierProg/lib/x64/SDL2main.lib C:/Users/pglan/CLionProjects/AtelierProg/lib/x64/SDL2.lib)
ELSE()
    target_link_libraries(PierreSandbox ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
    target_link_libraries(JulienSandbox ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} )
ENDIF()