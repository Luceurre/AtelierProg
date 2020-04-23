//
// Created by pglandon on 4/19/20.
//

#ifndef ATELIERPROG_SCENECONSOLE_H
#define ATELIERPROG_SCENECONSOLE_H

#include <cstdlib>
#include <SDL_ttf.h>

#include "../API/Scene.h"
#include "../API/WindowManager.h"
#include "../API/Console.h"

#define FONT_WIDTH 16
#define FONT_HEIGHT 32
#define INTERSPACE 0
#define TOPLEFT_MARGIN 20

class SceneConsole : public Scene, public Console {
    SDL_Window *consoleWindow;
    SDL_Renderer *consoleRenderer;
    TTF_Font *font;

    std::string inputed_text;
    std::string whole_text;
public:
    std::string descriptor() override;
    int initialize() override;
    int view() override ;
    int controller() override ;
    int model()override ;

    static void help(Console*);

    void input_text();

    void add_text(SDL_Keycode key);

    // Affiche à l'écran un texte
    void render_text(int x, int y, std::string text);

    // Affiche à l'écran une ligne
    void render_line(int x, int y, const std::string& line);

protected:
    void init_console(const std::string& consoleName) override ;

private:
    std::mutex buffer_mtx;
    std::mutex whole_text_mtx;
    std::string buffer;
    std::stringstream stream;

    // Console related commands
    static void set_bg_color(Console*, const std::vector<std::string>&, std::stringstream&);
    static void list_consoles(Console* c, const std::vector<std::string>& args, std::stringstream& output);
};


#endif //ATELIERPROG_SCENECONSOLE_H
