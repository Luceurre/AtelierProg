//
// Created by pglandon on 24/04/2020.
//

#include "MouseHandler.h"

void MouseHandler::handle_mouse(SDL_Event *event) {
    if(event->type == SDL_MOUSEMOTION) {
        mouseX = event->motion.x;
        mouseY = event->motion.y;
    }
    if(event->type == SDL_BUTTON_LEFT) {
        click = 1;
    }
    if( event->type == SDL_BUTTON_RIGHT){
        click = 2;
    }
    if(event->type == SDL_BUTTON_MIDDLE){
        click = 3;
    }
}
