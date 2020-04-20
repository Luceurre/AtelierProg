//
// Created by julien on 19/04/2020.
//

#ifndef ATELIERPROG_SPRITECOMPONENT_H
#define ATELIERPROG_SPRITECOMPONENT_H

#include "Components.h"
#include "SDL.h"
#include "../TextureManager.h"


class SpriteComponent : public Component {
private:
    TransformComponent *transform;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;

public:

    SpriteComponent() = default;
    SpriteComponent(const char* path) {
        setTex(path);
    }
    ~SpriteComponent() {
        SDL_DestroyTexture(texture);
    }


    void setTex(const char* path) {
        texture = TextureManager::LoadTexture(path);
    }

    void init() override {

        transform = &entity->getComponent<TransformComponent>();

        srcRect.h = transform->height;
        srcRect.w = transform->width;
        srcRect.x = 0;
        srcRect.y = 0;
    }

    void update() override {
        destRect.x = static_cast<int>(transform->position.x);
        destRect.y = static_cast<int>(transform->position.y);
        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;
    }

    void draw() override {
        TextureManager::Draw(texture, srcRect, destRect);
    }

};


#endif //ATELIERPROG_SPRITECOMPONENT_H
