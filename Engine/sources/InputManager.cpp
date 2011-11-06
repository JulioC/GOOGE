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
_keystate(NULL),
_lastKeystate(NULL),
_event() {
}

InputManager::~InputManager() {
    release();
}

bool InputManager::init() {
    if(!_initiated) {
        _keystate = SDL_GetKeyState(&_keystateCount);
        
        _lastKeystate = new Uint8[_keystateCount];
        memset(_lastKeystate, 0, _keystateCount * sizeof(Uint8));
        
        _initiated = true;
    }
    
    Log::message("InputManager initiated", this);
    
    return true;
}

void InputManager::release() {
    if(_initiated) {
        if(_lastKeystate != NULL) {
            delete _lastKeystate;
        }
        
        _initiated = false;
    }
    
    Log::message("InputManager released", this);
}

void InputManager::update() {
    memcpy(_lastKeystate, _keystate, _keystateCount * sizeof(Uint8));
    
    // Just catching the quit event
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
    
bool InputManager::keyDown(SDLKey key) const {
    return _keystate[key];
}

bool InputManager::keyUp(SDLKey key) const {
    return !_keystate[key];
}

bool InputManager::keyPressed(SDLKey key) const {
    return _keystate[key] && !_lastKeystate[key];
}
