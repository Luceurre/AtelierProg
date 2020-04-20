//
// Created by julien on 20/04/2020.
//

#ifndef ATELIERPROG_COLLISION_H
#define ATELIERPROG_COLLISION_H

#include "SDL.h"

class ColliderComponent;

class Collision {
public:
    static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
    static bool AABB(const ColliderComponent& colA, const ColliderComponent& colB);
};

#endif //ATELIERPROG_COLLISION_H
