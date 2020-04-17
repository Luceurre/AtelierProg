CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
SET(CMAKE_CXX_STANDARD 20)
PROJECT(AtelierProg)

FIND_PACKAGE(SDL2 REQUIRED)

add_executable(API_Tests main.cpp API/Logger.cpp API/Logger.h)

target_link_libraries(API_Tests SDL2::SDL2)