//
// Created by xdiam on 23/04/2020.
//

#include "MouseController.h"

void MouseController::mouse_update() {

}

void MouseController::mouse_init() {
    int state = SDL_CaptureMouse(static_cast<SDL_bool>(true));
    if (state ==-1)
        warn("No mouse detected");
}
