//
// Created by pglandon on 24/04/2020.
//

#include "SceneMenu.h"

int SceneMenu::initialize() {
    Scene::initialize();

    init_console("MENU");
    info("added as MENU in console");

    WindowManager::getInstance().add_primary_window(createDefaultWindow());
    window = WindowManager::getInstance().get_primary_window();
    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    TextureManager::renderer = renderer;

    auto& buttons(manager.addEntity());
    info("entity button created");
    buttons.addComponents<MouseComponent>(&mouseX, &mouseY);
    info("added MouseComponent to button");
    buttons.addComponents<SpriteComponent>("assets/Boutons_mieux/PNG/shiny/1.png");
    info("added SpriteComponent to button");
    buttons.addComponents<ClickableComponent>();
    info("added ClickableComponent to button");

    info("loading fonts.");
    this->font = TTF_OpenFont("fonts/FreeMono.ttf", 25);
    if(!font) {
        std::string msg = "Couldn't load FreeMono.ttf";
        error(msg);
    }

    set_model_refresh_rate(200);
    set_fps(UNCAPPED);

    return 0;
}

int SceneMenu::view() {
    SDL_RenderClear(renderer);

    manager.draw();

    // Draw Mouse pos
    SDL_Rect dest;
    dest.x = 0;
    dest.y = 0;
    dest.w = 100;
    dest.h = 100;

    SDL_Color color = { 255, 0, 0 };
    SDL_Surface * surface = TTF_RenderText_Solid(font,
                                                 (std::to_string(mouseX)+ ", " + std::to_string(mouseY)).c_str(), color);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderCopy(renderer, texture, NULL, &dest);

    SDL_RenderPresent(renderer);

    return Scene::view();
}

int SceneMenu::model() {
    manager.update();
    return Scene::model();
}

int SceneMenu::controller() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_MOUSEMOTION) {
            mouseX = event.motion.x;
            mouseY = event.motion.y;
        }
        if (event.type == SDL_QUIT) {
            exit(0);
        }
    }
    return Scene::controller();
}
