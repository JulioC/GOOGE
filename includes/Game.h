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
    
    int addScene(Scene* scene);
    bool removeScene(int index);
    bool activeScene(int index);
    
private:
    Game();
    Game(const Game& orig);
    const Game& operator=(const Game& orig);
    
    void releaseScenes();
    
    static Game* _instance;
    
    bool _ended;
    
    VideoManager* _video;
    InputManager* _input;
    
    std::vector<Scene*> _scenes;
    Scene* _currentScene;
};

#endif	/* GAME_H */

