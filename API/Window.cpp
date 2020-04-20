//
// Created by pglan on 20/04/2020.
//

#include "Window.h"
//
//Window::Window(int x, int y, int w, int h, Uint32 sdl_flags) {
//    this->x = x;
//    this->y = y;
//    this->w = w;
//    this->h = h;
//    this->sdl_flags = sdl_flags;
//}

Window* createDefaultWindow() {
    return SDL_CreateWindow("Default", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 800, 0);
}