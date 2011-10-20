#include "InputManager.h"

#include "Log.h"
#include "Game.h"

InputManager* InputManager::_instance = NULL;

InputManager* InputManager::instance() {
    if(_instance == NULL) {
        _instance = new InputManager();
    }
    
    return _instance;
}

InputManager::InputManager():
_initiated(false),
_terminated(false),
_keystate(0),
_event() {
}

InputManager::~InputManager() {
    release();
}

bool InputManager::init() {
    if(!_initiated) {
        _keystate = SDL_GetKeyState(NULL);
    
        _initiated = true;
    }
    
    Log::message("InputManager initiated", this);
    
    return true;
}

void InputManager::release() {
    if(_initiated) {
    
        _initiated = false;
    }
    
    Log::message("InputManager released", this);
}

void InputManager::update() {
    // No events need to be catch
    while(SDL_PollEvent(&_event)) {
        if(_event.type == SDL_QUIT) {
            _terminated = true;
        }
    }
    
    // The _keystate will update on calling for PollEvent
}

bool InputManager::initiated() const {
    return _initiated;
}

bool InputManager::terminated() const {
    return _terminated;
}
