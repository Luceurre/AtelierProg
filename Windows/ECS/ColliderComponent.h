//
// Created by julien on 20/04/2020.
//

#ifndef ATELIERPROG_COLLIDERCOMPONENT_H
#define ATELIERPROG_COLLIDERCOMPONENT_H

#include "SDL.h"
#include <string>
#include "Components.h"

class ColliderComponent : public Component {
public:

    SDL_Rect collider;
    std::string tag;

    TransformComponent* transform;

    ColliderComponent(std::string t) {
        tag = t;
    }

    void init() override {
        if (!entity->hasComponent<TransformComponent>()) {
            entity->addComponents<TransformComponent>();
        }
        transform = &entity->getComponent<TransformComponent>();

        Game::colliders.push_back(this);
    }

    void update() override {
        collider.x = static_cast<int>(transform->position.x);
        collider.y = static_cast<int>(transform->position.y);
        collider.w = transform->width * transform->scale;
        collider.h = transform->height * transform->scale;
    };
};


#endif //ATELIERPROG_COLLIDERCOMPONENT_H
