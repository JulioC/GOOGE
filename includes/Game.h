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
    
protected:
    Game();
    
    int addScene(Scene* scene);
    bool removeScene(int index);
    bool activateScene(int index);
    
    void setTitle(const char* title);
    
private:
    Game(const Game&);
    const Game& operator=(const Game&);
    
    void releaseScenes();
    
    static Game* _instance;
    
    bool _ended;
    
    VideoManager* _video;
    InputManager* _input;
    
    std::vector<Scene*> _scenes;
    Scene* _activeScene;
};

#endif	/* GAME_H */

