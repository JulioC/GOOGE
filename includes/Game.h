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
    
    bool setup();
    void cleanup();
    
    void run();
    
    bool running() const;
    
// @TODO: Create scene management
    bool activeScene(int index, bool temp=false);
    Scene* activeScene();
    
private:
    Game();
    Game(const Game& orig);
    const Game& operator=(const Game& orig);
    
    static Game* _instance;
    
    bool _quit;
    
    VideoManager* _video;
    InputManager* _input;
    
    std::vector<Scene*> _scenes;
    Scene* _activeScene;
    
};

#endif	/* GAME_H */

