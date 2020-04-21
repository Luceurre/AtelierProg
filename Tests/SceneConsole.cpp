//
// Created by pglandon on 4/19/20.
//

#include "SceneConsole.h"

int SceneConsole::initialize() {
    int codeResult = Scene::initialize();

    SDL_Init(SDL_INIT_EVERYTHING);

    for(int i = 0; i > -1; --i) {
        this->consoleWindow = createDefaultWindow();
        WindowManager::getInstance().add_primary_window(this->consoleWindow);

        this->consoleRenderer = SDL_CreateRenderer(this->consoleWindow, -1, SDL_RENDERER_PRESENTVSYNC);

        SDL_RenderClear(this->consoleRenderer);
        SDL_RenderPresent(this->consoleRenderer);
    }

    set_fps(UNCAPPED);
    set_model_refresh_rate(10000);

    nb_color = 0;
    nb_color_vue = 0;

    Command cmd;
    cmd.name = std::string("help");
    cmd.callback = SceneConsole::help;

    this->commands.push_back(cmd);

    this->commands[0].callback(this);

    return 0;
}

std::string SceneConsole::descriptor() {
    return "(Console)";
}

int SceneConsole::model() {
    Scene::model();

    this->r = rand() % 256;
    g = rand() % 256;
    b = rand() % 256;

    nb_color++;

    return 0;
}

int SceneConsole::view() {
    SDL_SetRenderDrawColor(this->consoleRenderer, r, g, b, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(this->consoleRenderer);
    SDL_RenderPresent(this->consoleRenderer);

    nb_color_vue++;

    return 0;
}

void SceneConsole::help(SceneConsole* sc) {
    sc->set_state(DESTROYED);
}
