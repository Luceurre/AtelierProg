//
// Created by pglandon on 24/04/2020.
//

#ifndef ATELIERPROG_CLICKABLECOMPONENT_H
#define ATELIERPROG_CLICKABLECOMPONENT_H

class ClickableComponent : public Component {
public:
  bool clicked = false;

  void init() override {
      if(!entity->hasComponent<MouseComponent>()) {
          std::cout << "MouseComponent is needed to work!";
          exit(-1);
      }
  }
};

#endif //ATELIERPROG_CLICKABLECOMPONENT_H
