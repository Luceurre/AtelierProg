//
// Created by mathis on 20/04/2020.
//
#include "Events/EventIncluder.h"
#include "SDL.h"

int main(int argc, char *argv[])
{
    /*
    EventManager gameEventManager;

    Dog chien;
    Cat chat;

    gameEventManager.AddEventSubject(EventType::KeyPressed,cb::Make1(&chien, &Dog::notify));
    gameEventManager.AddEventSubject(EventType::KeyPressed,cb::Make1(&chat, &Cat::notify));

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win;
    SDL_Renderer* rend;

    SDL_CreateWindowAndRenderer(640, 480, 0, &win, &rend);

    SDL_Event event;


    while(1) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                exit(0);
            }

            if(event.type == SDL_KEYDOWN){
                KeyPressedEvent a (32,1);
                gameEventManager.Dispatch(a);

                gameEventManager.RemoveEventSubject(EventType::KeyPressed, cb::Make1(&chat, &Cat::notify));
            }
        }
    }
*/

    uint32_t num = 9;
    uint32_t b0,b1,b2,b3;
    uint32_t res;

    b0 = (num & 0x000000ff) << 24u;
    b1 = (num & 0x0000ff00) << 8u;
    b2 = (num & 0x00ff0000) >> 8u;
    b3 = (num & 0xff000000) >> 24u;

    res = b0 | b1 | b2 | b3;




    return 0;
}
