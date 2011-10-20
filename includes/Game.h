#ifndef GAME_H
#define	GAME_H

#include <stack>
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
    
    bool ended() const;
    
// @TODO: Create scene management
    bool activeScene(int index, bool temp=false);
    Scene* currentScene();
    
private:
    Game();
    Game(const Game& orig);
    const Game& operator=(const Game& orig);
    
    static Game* _instance;
    
    bool _ended;
    
    VideoManager* _video;
    InputManager* _input;
    
    std::vector<Scene*> _scenes;
    std::stack<Scene*> _activeScenes;
    Scene* _currentScene;
    
    
    
};

#endif	/* GAME_H */

