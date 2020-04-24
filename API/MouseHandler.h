//
// Created by pglandon on 24/04/2020.
//

#ifndef ATELIERPROG_MOUSEHANDLER_H
#define ATELIERPROG_MOUSEHANDLER_H


#include <SDL_events.h>

class MouseHandler {
protected:
    int mouseX;
    int mouseY;

    void handle_mouse(SDL_Event* event);
};


#endif //ATELIERPROG_MOUSEHANDLER_H
