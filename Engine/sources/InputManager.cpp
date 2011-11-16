#include "InputManager.h"

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
_keystateCount(0),
_keyState(NULL),
_prevKeyState(NULL),
_mouseState(0),
_prevMouseState(0),
_mousePosition(NULL),
_prevMousePosition(NULL),
_event() {
}

InputManager::~InputManager() {
    release();
}

bool InputManager::init() {
    if(!_initiated) {
        _keyState = SDL_GetKeyState(&_keystateCount);
        
        _prevKeyState = new Uint8[_keystateCount];
        memset(_prevKeyState, 0, _keystateCount * sizeof(Uint8));
        
        _mousePosition = new Vector(0, 0);
        _prevMousePosition = new Vector(0, 0);
        
        _initiated = true;
    }
    
    Log::message(this, "InputManager initiated");
    
    return true;
}

void InputManager::release() {
    if(_initiated) {
        if(_prevKeyState != NULL) {
            delete[] _prevKeyState;
        }
        
        if(_mousePosition != NULL) {
            delete _mousePosition;
        }
        
        if(_prevMousePosition != NULL) {
            delete _prevMousePosition;
        }
        
        _initiated = false;
    }
    
    Log::message(this, "InputManager released");
}

void InputManager::update() {
    // Store the previous states from keyboard
    // _keyState will be updated on calling for PollEvent
    memcpy(_prevKeyState, _keyState, _keystateCount * sizeof(Uint8));
    
    
    // Just catching the quit event
    while(SDL_PollEvent(&_event)) {
        if(_event.type == SDL_QUIT) {
            _terminated = true;
        }
    }
    
    // Update the mouse position and state
    int x = 0;
    int y = 0;
    
    _prevMouseState = _mouseState;
    _mouseState = SDL_GetMouseState(&x, &y);
    
    delete _prevMousePosition;
    _prevMousePosition = _mousePosition;
    _mousePosition = new Vector((float)x, (float)y);    
}

bool InputManager::initiated() const {
    return _initiated;
}

bool InputManager::terminated() const {
    return _terminated;
}
    
bool InputManager::keyDown(SDLKey key) const {
    if(_keyState == NULL) {
        return false;
    }
    
    return _keyState[key];
}

bool InputManager::keyUp(SDLKey key) const {
    if(_keyState == NULL) {
        return false;
    }
    
    return !_keyState[key];
}

bool InputManager::keyPressed(SDLKey key) const {
    if(_keyState == NULL || _prevKeyState == NULL) {
        return false;
    }
    
    return _keyState[key] && !_prevKeyState[key];
}

Vector InputManager::mousePosition() const {
    if(_mousePosition == NULL) {
        return Vector(0, 0);
    }
    
    return (*_mousePosition);
}

Vector InputManager::mouseMotion() const {
    if(_mousePosition == NULL || _prevMousePosition == NULL) {
        return Vector(0, 0);
    }
    
    return (*_mousePosition) - (*_prevMousePosition);
}

bool InputManager::mouseDown(int button) const {
    return _mouseState & SDL_BUTTON(button);
}

bool InputManager::mouseUp(int button) const {
    return !(_mouseState & SDL_BUTTON(button));
}

bool InputManager::mousePressed(int button) const {
    return (_mouseState & SDL_BUTTON(button))
        && !(_prevMouseState & SDL_BUTTON(button));
 }