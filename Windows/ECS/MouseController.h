//
// Created by xdiam on 23/04/2020.
//

#ifndef ATELIERPROG_MOUSECONTROLLER_H
#define ATELIERPROG_MOUSECONTROLLER_H

#include "../../API/Logger.h"
#include "SDL.h"



class MouseController : protected Logger{
public :
    int x,y;        //Mouse position

    void mouse_update();
    void mouse_init();

    std::string descriptor() override;
};


#endif //ATELIERPROG_MOUSECONTROLLER_H
