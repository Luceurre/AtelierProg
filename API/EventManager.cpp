//
// Created by pglan on 25/04/2020.
//

#include "EventManager.h"

std::map<event_cond, std::vector<callback_method>> EventManager::custom_events;

void EventManager::add_custom_event_watch(event_cond callback_condition, callback_method method) {
    auto exists = EventManager::custom_events.find(callback_condition);
    if (exists == EventManager::custom_events.end()) {
        // Cette condition n'existe pas, on l'ajoute
        std::vector<callback_method> methods;
        methods.push_back(method);
        EventManager::custom_events.emplace(callback_condition, methods);

        return;
    }
    EventManager::custom_events.at(callback_condition).push_back(method);
}

void EventManager::add_sdl_event_watch(SDL_EventType eventType, callback_method method) {
    auto exists = EventManager::sdl_events.find(eventType);
    if (exists == EventManager::sdl_events.end()) {
        // Cette condition n'existe pas, on l'ajoute
        std::vector<callback_method> methods;
        methods.push_back(method);
        EventManager::sdl_events.emplace(eventType, methods);

        return;
    }
    EventManager::sdl_events.at(eventType).push_back(method);
}
