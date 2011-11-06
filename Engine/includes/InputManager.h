#ifndef INPUTMANAGER_H
#define	INPUTMANAGER_H

#include "SDL/SDL.h"
#include "Object.h"

#include "Vector.h"

class InputManager: public Object {
public:
    static InputManager* instance();
    
    ~InputManager();
    
    bool init();
    void release();
    
    void update();
    
    bool initiated() const;
    bool terminated() const;
    
    bool keyDown(SDLKey key) const;
    bool keyUp(SDLKey key) const;
    bool keyPressed(SDLKey key) const;
    
    Vector mousePosition() const;
    Vector mouseMotion() const;
    
    bool mouseDown(int button) const;
    bool mouseUp(int button) const;
    bool mousePressed(int button) const;
    
private:
    InputManager();
    InputManager(const InputManager&);
    const InputManager& operator=(const InputManager&);
    
    static InputManager* _instance;
    
    bool _initiated;
    bool _terminated;
    
    int _keystateCount;
    Uint8* _keyState;
    Uint8* _prevKeyState;
    
    Uint8 _mouseState;
    Uint8 _prevMouseState;
    Vector* _mousePosition;
    Vector* _prevMousePosition;
    
    SDL_Event _event;
};

#endif	/* INPUTMANAGER_H */

