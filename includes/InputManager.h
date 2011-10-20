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
    
private:
    InputManager();
    InputManager(const InputManager&);
    const InputManager& operator=(const InputManager&);
    
    static InputManager* _instance;
    
    bool _initiated;
    bool _terminated;
    
    Uint8* _keystate;
    SDL_Event _event;
};

#endif	/* INPUTMANAGER_H */

