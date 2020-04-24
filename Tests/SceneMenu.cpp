//
// Created by pglandon on 24/04/2020.
//

#include "SceneMenu.h"
#include "../Windows/ECS/Components.h"

int SceneMenu::initialize() {
    init_console("MENU");

    auto& buttons(manager.addEntity());
    buttons.addComponents<MouseComponent>(&mouseX, &mouseY);
    buttons.addComponents<SpriteComponent>();
    buttons.addComponents<ClickableComponent>();

    return Scene::initialize();
}
