//
// Created by pglan on 20/04/2020.
//

#ifndef ATELIERPROG_WINDOW_H
#define ATELIERPROG_WINDOW_H


#include "Logger.h"

typedef SDL_Window Window;

//
//class Window : public Logger{
//    int x, y, w, h;
//    Uint32 sdl_flags;
//    char* title
//public:
//    Window(char* title, int x, int y, int w, int h, Uint32 sdl_flags);
//};

// Crée une fenetre pour des besoins de tests.
Window* createDefaultWindow();


#endif //ATELIERPROG_WINDOW_H
