//
// Created by pglandon on 4/23/20.
//

#include <SDL.h>

void mouse_handling() {
    // Notre structure qui contiendra l'ensemble des informations sur l'événement qui est arrivé
    SDL_Event event;

    // Tant que la pile des événements n'est pas vide, event devient le premier élément de la FILE.
    while (SDL_PollEvent(&event)) {
        // On check si c'est bien un
        if(event.type == SDL_MOUSEMOTION) {

        }
    }
}