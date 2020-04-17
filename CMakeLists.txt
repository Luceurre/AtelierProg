CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
PROJECT(AtelierProg)

FIND_PACKAGE(SDL2 REQUIRED)
FIND_PACKAGE(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(PierreSandbox main_pierre.cpp API/Logger.cpp API/Logger.h API/Scene.cpp API/Scene.h API/SceneView.cpp API/SceneView.h API/SceneLogic.cpp API/SceneLogic.h)
add_executable(JulienSandbox main_julien.cpp)


target_link_libraries(PierreSandbox ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
