//
// Created by pglandon on 24/04/2020.
//

#ifndef ATELIERPROG_CLICKABLECOMPONENT_H
#define ATELIERPROG_CLICKABLECOMPONENT_H

class ClickableComponent : public Component {
public:
    bool clicked = false;
    bool hovered = false;

  MouseComponent* mouseComponent;
  SpriteComponent* spriteComponent;
  SDL_Texture* hovered_texture;
  SDL_Rect hovered_texture_rect;

  void init() override {
      if(!entity->hasComponent<MouseComponent>()) {
          std::cout << "MouseComponent is needed to work!";
          exit(-1);
      }
      if(!entity->hasComponent<SpriteComponent>()) {
          std::cout << "SpriteComponent is needed to work!";
          exit(-1);
      }

      mouseComponent = &entity->getComponent<MouseComponent>();
      spriteComponent = &entity->getComponent<SpriteComponent>();

      hovered_texture = TextureManager::LoadTexture("assets/Boutons_mieux/PNG/shiny/2.png", hovered_texture_rect);
  }

  void update() override {
      if (spriteComponent->destRect.x <= *mouseComponent->mouse_x && spriteComponent->destRect.x + \
      spriteComponent->destRect.w > *mouseComponent->mouse_x) {
          if (spriteComponent->destRect.y <= *mouseComponent->mouse_y && spriteComponent->destRect.y + \
      spriteComponent->destRect.h > *mouseComponent->mouse_y) {
            if (!hovered) {
                hovered = true;
                std::cout << "You're on the button" << std::endl;
                SDL_Texture *tempTexture = spriteComponent->texture;
                spriteComponent->texture = hovered_texture;
                hovered_texture = tempTexture;
            }
          }
      } else {
    hovered = false;
}
  }
};

#endif //ATELIERPROG_CLICKABLECOMPONENT_H
