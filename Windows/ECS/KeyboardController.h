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
    SpriteComponent *sprite;
    SDL_Event *event;

    explicit KeyboardController(SDL_Event* event) {
        this->event = event;
        transform = nullptr;
        sprite = nullptr;
    }

    void init() override {
        if(!event) {
            std::cout << "Erreur!" << std::endl;
            exit(-1);
        }
        transform = &entity->getComponent<TransformComponent>();
        sprite = &entity->getComponent<SpriteComponent>();
    }

    void update() override {
        if (event->type == SDL_KEYDOWN) {
            switch (Game::event.key.keysym.sym) {
                case SDLK_z:
                    transform->velocity.y = -1;
                    sprite->play("Walk");
                    break;
                case SDLK_q:
                    transform->velocity.x = -1;
                    sprite->play("Walk");
                    sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
                    break;
                case SDLK_s:
                    transform->velocity.y = 1;
                    sprite->play("Walk");
                    break;
                case SDLK_d:
                    transform->velocity.x = 1;
                    sprite->play("Walk");
                    break;
                default:
                    break;
            }
        }

        else if (Game::event.type == SDL_KEYUP) {
            switch (Game::event.key.keysym.sym) {
                case SDLK_z:
                    transform->velocity.y = 0;
                    sprite->play("Idle");
                    break;
                case SDLK_q:
                    transform->velocity.x = 0;
                    sprite->play("Idle");
                    sprite->spriteFlip = SDL_FLIP_NONE;
                    break;
                case SDLK_s:
                    transform->velocity.y = 0;
                    sprite->play("Idle");
                    break;
                case SDLK_d:
                    transform->velocity.x = 0;
                    sprite->play("Idle");
                    break;
                default:
                    break;
            }
        }
    }
};

#endif //ATELIERPROG_KEYBOARDCONTROLLER_H