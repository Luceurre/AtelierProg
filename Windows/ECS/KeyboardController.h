//
// Created by julien on 19/04/2020.
//
#pragma once
#ifndef ATELIERPROG_KEYBOARDCONTROLLER_H
#define ATELIERPROG_KEYBOARDCONTROLLER_H

#include "../Game.h"
#include "ECS.h"
#include "Components.h"

class KeyboardController : public Component {
public:
    TransformComponent *transform;

    void init() override {
        transform = &entity->getComponent<TransformComponent>();
    }

    void update() override {
        if (Game::event.type == SDL_KEYDOWN) {
            switch (Game::event.key.keysym.sym) {
                case SDLK_z:
                    transform->velocity.y = -1;
                    break;
                case SDLK_q:
                    transform->velocity.x = -1;
                    break;
                case SDLK_s:
                    transform->velocity.y = 1;
                    break;
                case SDLK_d:
                    transform->velocity.x = 1;
                    break;
                default:
                    break;
            }
        }

        else if (Game::event.type == SDL_KEYUP) {
            switch (Game::event.key.keysym.sym) {
                case SDLK_z:
                    transform->velocity.y = 0;
                    break;
                case SDLK_q:
                    transform->velocity.x = 0;
                    break;
                case SDLK_s:
                    transform->velocity.y = 0;
                    break;
                case SDLK_d:
                    transform->velocity.x = 0;
                    break;
                default:
                    break;
            }
        }
    }
};

#endif //ATELIERPROG_KEYBOARDCONTROLLER_H