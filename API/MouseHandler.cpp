//
// Created by pglandon on 24/04/2020.
//

#include "MouseHandler.h"

void MouseHandler::handle_mouse(SDL_Event *event) {
    if(event->type == SDL_MOUSEMOTION) {
        mouseX = event->motion.x;
        mouseY = event->motion.y;
    }
}
