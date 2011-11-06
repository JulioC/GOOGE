#ifndef GAME_H
#define	GAME_H

#include <vector>

#include "Object.h"
#include "VideoManager.h"
#include "InputManager.h"
#include "Scene.h"

class Game: public Object {
public:
    static Game* instance();
    
    virtual ~Game();
    
    virtual bool setup();
    virtual void cleanup();
    
    virtual void run();
    
    bool ended() const;
    
    void setNextScene(Scene* scene);
    
protected:
    Game();
    
    void setTitle(const char* title);
    
    VideoManager* _video;
    InputManager* _input;
    
private:
    Game(const Game&);
    const Game& operator=(const Game&);
    
    bool activeNextScene();
    
    static Game* _instance;
    
    bool _ended;
    
    Scene* _activeScene;
    Scene* _nextScene;
};

#endif	/* GAME_H */

