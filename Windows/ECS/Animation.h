//
// Created by julien on 21/04/2020.
//

#ifndef ATELIERPROG_ANIMATION_H
#define ATELIERPROG_ANIMATION_H

struct Animation {
    int index;
    int frames;
    int speed;

    Animation() {}
    Animation(int i, int f, int s) {
        index = i;
        frames = f;
        speed = s;
    }
};

#endif //ATELIERPROG_ANIMATION_H
