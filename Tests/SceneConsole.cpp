//
// Created by pglandon on 4/19/20.
//

#include "SceneConsole.h"

int SceneConsole::initialize() {
    int codeResult = Scene::initialize();

    SDL_Init(SDL_INIT_EVERYTHING);
    if(TTF_Init() == -1) {
        std::string msg = "Couldn't load SDL2_ttf";
        this->error(msg);
    }

    this->font = TTF_OpenFont("fonts/FreeMono.ttf", 25);
    if(!font) {
        std::string msg = "Couldn't load FreeMono.ttf";
        error(msg);
    }

    for(int i = 0; i > -1; --i) {
        this->consoleWindow = createDefaultWindow();
        WindowManager::getInstance().add_primary_window(this->consoleWindow);

        this->consoleRenderer = SDL_CreateRenderer(this->consoleWindow, -1, SDL_RENDERER_PRESENTVSYNC);

        SDL_RenderClear(this->consoleRenderer);
        SDL_RenderPresent(this->consoleRenderer);
    }

    set_fps(UNCAPPED);
    set_model_refresh_rate(200);

    return 0;
}

std::string SceneConsole::descriptor() {
    return "(Console)";
}

int SceneConsole::controller() {
    Scene::controller();

    SDL_Event e;
    while(SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_QUIT:
                this->set_state(DESTROYED);
                break;
            case SDL_KEYDOWN:
                SDL_Keycode key = e.key.keysym.sym;
                switch (key) {
                    case SDLK_RETURN:
                        this->input_text();
                        break;
                    case SDLK_BACKSPACE:
                        if (!inputed_text.empty()) {
                            this->inputed_text.pop_back();
                        }
                        break;
                    default:
                        this->add_text(key);
                        break;
                }
                if (key == SDLK_RETURN) {
                    this->input_text();
                }
        }
    }

    return 0;
}

int SceneConsole::view() {
    SDL_RenderClear(this->consoleRenderer);

    this->render_text(TOPLEFT_MARGIN, TOPLEFT_MARGIN, this->whole_text + this->inputed_text );

    SDL_RenderPresent(this->consoleRenderer);

    return 0;
}

void SceneConsole::help(SceneConsole* sc) {
    sc->set_state(DESTROYED);
}

void SceneConsole::input_text() {
    this->whole_text += this->inputed_text + '\n';
    // Run command here and add output to whole_text
    std::lock_guard<std::mutex> lock(buffer_mtx);
    this->buffer = this->inputed_text;

    this->inputed_text = "";
}

void SceneConsole::add_text(SDL_Keycode key) {
    switch (key) {
        case SDLK_SPACE:
            this->inputed_text += " ";
            break;
        default:
            this->inputed_text += SDL_GetKeyName(key);
    }
}

void SceneConsole::render_text(int x, int y, std::string text) {
    int nbLine = 1;

    for(auto car : text) {
        if (car == '\n') {
            nbLine++;
        }
    }

    int i = 0;
    std::string lines[nbLine];
    for(auto car : text) {
        if(car == '\n') {
            i++;
        } else {
            lines[i] += car;
        }
    }

    for(int j = 0; j < nbLine; j++) {
        this->render_line(x, y + j * (FONT_HEIGHT / 2 + INTERSPACE), lines[j]);
    }
}

void SceneConsole::render_line(int x, int y, const std::string& line) {
    int max = 0;
    int currentLine = 0;
    for(auto car : line) {
        if (car == '\n') {
            if (currentLine > max) {
                max = currentLine;
            }
            currentLine = 0;
        } else {
            currentLine++;
        }
    }
    if (currentLine > max) {
        max = currentLine;
    }

    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = max * FONT_WIDTH;
    dest.h = FONT_HEIGHT;

    SDL_Color color = { 255, 255, 255 };
    SDL_Surface * surface = TTF_RenderText_Solid(font,
                                                 line.c_str(), color);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(consoleRenderer, surface);
    SDL_RenderCopy(consoleRenderer, texture, NULL, &dest);
}
