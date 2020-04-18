//
// Created by julien on 18/04/2020.
//
#pragma once
#ifndef ATELIERPROG_TEXTUREMANAGER_H
#define ATELIERPROG_TEXTUREMANAGER_H

#include "Game.h"

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char* fileName);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};



#endif //ATELIERPROG_TEXTUREMANAGER_H
