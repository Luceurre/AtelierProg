//
// Created by julien on 18/04/2020.
//

#include "TextureManager.h"

SDL_Renderer* TextureManager::renderer = nullptr;

SDL_Texture* TextureManager::LoadTexture(const char *fileName, SDL_Rect &texture_dimension) {
    SDL_Surface* tempSurface = IMG_Load(fileName);
    texture_dimension.w = tempSurface->w;
    texture_dimension.h = tempSurface->h;
    SDL_Texture* tex = SDL_CreateTextureFromSurface(TextureManager::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return tex;

}

void TextureManager::Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip) {
    SDL_RenderCopyEx(TextureManager::renderer, tex, &src, &dest, NULL, NULL, flip);
}
