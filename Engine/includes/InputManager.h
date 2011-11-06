#ifndef INPUTMANAGER_H
#define	INPUTMANAGER_H

#include "SDL/SDL.h"
#include "Object.h"


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
    
private:
    InputManager();
    InputManager(const InputManager&);
    const InputManager& operator=(const InputManager&);
    
    static InputManager* _instance;
    
    bool _initiated;
    bool _terminated;
    
    int _keystateCount;
    Uint8* _keystate;
    Uint8* _lastKeystate;
    
    SDL_Event _event;
};

#endif	/* INPUTMANAGER_H */

