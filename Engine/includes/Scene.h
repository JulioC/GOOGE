#ifndef SCENE_H
#define	SCENE_H

#include "Object.h"

class Game;
class VideoManager;
class InputManager;

class Scene: public Object {
public:
    Scene();
    Scene(Game* parent, VideoManager* video, InputManager* input);
    virtual ~Scene();
    
    virtual bool init();
    virtual void release();
    
    virtual void update() = 0;
    virtual void draw() = 0;
    
    void game(Game* parent);
    void videoManager(VideoManager* video);
    void inputManager(InputManager* input);
    
    bool active() const;
    
private:
    Scene(const Scene&);
    const Scene& operator=(const Scene&);
    
    bool _active;
    
    Game* _game;
    VideoManager* _video;
    InputManager* _input;
};

#endif	/* SCENE_H */

