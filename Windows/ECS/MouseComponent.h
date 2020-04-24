//
// Created by pglandon on 4/23/20.
//

#ifndef ATELIERPROG_MOUSECOMPONENT_H
#define ATELIERPROG_MOUSECOMPONENT_H

class MouseComponent : public Component {
public:
    MouseComponent(int* mouseX , int* mouseY) {
        this->mouse_x = mouseX;
        this->mouse_y = mouseY;
    }

private:
    int* mouse_x;
    int* mouse_y;
};

#endif //ATELIERPROG_MOUSECOMPONENT_H
