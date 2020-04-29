//
// Created by pglan on 25/04/2020.
//

#ifndef ATELIERPROG_EVENTMANAGER_H
#define ATELIERPROG_EVENTMANAGER_H

#include <SDL_events.h>
#include <map>
#include <vector>

// The idea is to introduce event callback
// instead of just passing the event to each entity.
// The event manager is used to register Events for a given
// scene and then call its callback on the "right" time.
// TODO : add custom events management

// It is yet a singleton (again ?!) but I think
// it's gonna turn into a Scene dependent object
// (like a static map of event manager with Scene/EventManager association)

// Questions :
// Should it be linked to a scene ?

// Define the function that should test if the event should be treated
using event_cond = bool (*)(SDL_Event& event);
using callback_method = void (*)(void*);

class EventManager {
    static std::map<event_cond, std::vector<callback_method>> custom_events;
    static std::map<SDL_EventType , std::vector<callback_method>> sdl_events;

    void add_custom_event_watch(event_cond, callback_method);
    void add_sdl_event_watch(SDL_EventType eventType, callback_method method);
};


#endif //ATELIERPROG_EVENTMANAGER_H
