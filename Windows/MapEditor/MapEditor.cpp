//
// Created by julien on 22/04/2020.
//

#include "MapEditor.h"

#include "SDL.h"
#include <stdio.h>

void test() {

    SDL_Window *window;                    // Declare a pointer
    SDL_Window *window2;

    SDL_DisplayMode current;
    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    SDL_GetCurrentDisplayMode(0, &current);

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
            "An SDL2 window",                  // window title
            0,           // initial x position
            0,           // initial y position
            current.w/3,                               // width, in pixels
            current.h,                               // height, in pixels
            SDL_WINDOW_RESIZABLE                  // flags - see below

    );

    window2 = SDL_CreateWindow(
            "An SDL2 window2",                  // window title
            current.w/3,           // initial x position
            0,           // initial y position
            2*current.w/3,                               // width, in pixels
            current.h,                               // height, in pixels
            SDL_WINDOW_RESIZABLE                  // flags - see below

    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
    }

    // The window is open: could enter program loop here (see SDL_PollEvent())

    SDL_Delay(10000);

    // Close and destroy the window
    SDL_DestroyWindow(window);
    SDL_DestroyWindow(window2);

    // Clean up
    SDL_Quit();
}