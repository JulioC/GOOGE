#ifndef GAME_H
#define	GAME_H

#include <vector>

#include "defs.h"
#include "InputManager.h"
#include "VideoManager.h"
#include "Scene.h"

class Game: public Object {
public:    
    Game();
    virtual ~Game();
    
    virtual bool setup();
    virtual void cleanup();
    
    virtual void run();
    
    bool ended() const;
    
    VideoManager* video() const;
    InputManager* input() const;
    
    void setNextScene(Scene* scene);
    
protected:    
    void setTitle(const char* title);
        
    VideoManager* _video;
    InputManager* _input;
    
private:
    Game(const Game&);
    const Game& operator=(const Game&);
    
    bool activeNextScene();
    
    bool _ended;
    
    Scene* _activeScene;
    Scene* _nextScene;
};

#endif	/* GAME_H */

