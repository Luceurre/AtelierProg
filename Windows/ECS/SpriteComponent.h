//
// Created by julien on 19/04/2020.
//

#ifndef ATELIERPROG_SPRITECOMPONENT_H
#define ATELIERPROG_SPRITECOMPONENT_H

#include "Components.h"
#include "SDL.h"
#include "../TextureManager.h"
#include "Animation.h"
#include <map>

class SpriteComponent : public Component {
private:
    TransformComponent *transform;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;

    bool animated = false;
    int frames = 0;
    int speed = 100;

public:

    int animIndex = 0;
    std::map<const char*, Animation> animations;

    SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

    SpriteComponent() = default;
    SpriteComponent(const char* path) {
        setTex(path);
    }
    SpriteComponent(const char* path, bool isAnimated) {
        animated = isAnimated;

        Animation idle = Animation(0, 3, 100);
        Animation walk = Animation(1, 8, 100);

        animations.emplace("Idle", idle);
        animations.emplace("Walk", walk);

        play("Idle");
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

        if (animated) {
            srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
        }

        srcRect.y = animIndex * transform->height;

        destRect.x = static_cast<int>(transform->position.x) - Game::camera.x;
        destRect.y = static_cast<int>(transform->position.y) - Game::camera.y;
        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;
    }

    void draw() override {
        TextureManager::Draw(texture, srcRect, destRect, spriteFlip);
    }

    void play(const char* animName) {
        frames = animations[animName].frames;
        animIndex = animations[animName].index;
        speed = animations[animName].speed;
    }

};


#endif //ATELIERPROG_SPRITECOMPONENT_H
