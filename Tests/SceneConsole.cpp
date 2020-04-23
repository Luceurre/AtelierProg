//
// Created by pglandon on 4/19/20.
//

#include "SceneConsole.h"
#include "../API/tools.h"

int SceneConsole::initialize() {
    int codeResult = Scene::initialize();

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

    // On enregistre la scène pour faire tourner des commandes dessus...
    // Full majuscule sinon ça fonctionne po...
    init_console("SCENECONSOLE");

    return 0;
}

std::string SceneConsole::descriptor() {
    return "(Console)";
}


int SceneConsole::model() {
    Scene::model();

    if (!buffer.empty()) {
        // On parse le buffer et on appelle la bonne commande
        std::vector<std::string> res = split(buffer, ' ');
        std::stringstream os;

        Console::process_command(res, os);

        std::lock_guard<std::mutex> lock(whole_text_mtx);
        whole_text += os.str();

        // On vite le buffer
        buffer = "";
    }

    return 0;
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

void SceneConsole::help(Console* sc) {
    auto *realSC = (SceneConsole *)sc;
    realSC->set_state(DESTROYED);
}

void SceneConsole::input_text() {
    this->whole_text += this->inputed_text + '\n';
    // Run command here and add output to whole_text
    std::lock_guard<std::mutex> lock(buffer_mtx);
    this->buffer.assign(this->inputed_text);
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

void SceneConsole::set_bg_color(Console *c, const std::vector<std::string>& args, std::stringstream& output_stream) {
    auto* sc = (SceneConsole*) c;
    if(args.size() == 4) {
        int r = std::stoi(args[0]);
        int g = std::stoi(args[1]);
        int b = std::stoi(args[2]);
        int a = std::stoi(args[3]);
        SDL_SetRenderDrawColor(sc->consoleRenderer, r, g, b, a);
    } else {
        output_stream << "Usage: BGCOLOR R G B A" << std::endl;
    }

}

void SceneConsole::init_console(const std::string& consoleName) {
    Console::init_console(consoleName);

    commands.emplace("BGCOLOR", SceneConsole::set_bg_color);
    commands.emplace("LIST", SceneConsole::list_consoles);
}

void SceneConsole::list_consoles(Console *c, const std::vector<std::string>& args, std::stringstream &output) {
    std::vector<std::string> consolesName;

    Console::get_consoles_name(consolesName);
    for(const auto& name : consolesName) {
        output << name << std::endl;
    }
}
