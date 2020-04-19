//
// Created by pglandon on 4/17/20.
//
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include "Tests/SceneConsole.h"

int main() {

    auto* console = new SceneConsole();
    console->initialize();
    console->run();

    return 0;
}