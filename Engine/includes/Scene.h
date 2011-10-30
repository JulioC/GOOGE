#ifndef SCENE_H
#define	SCENE_H

#include <vector>

#include "Object.h"

class Game;
class VideoManager;
class InputManager;
class Layer;

class Scene: public Object {
public:
    Scene();
    Scene(Game* parent, VideoManager* video, InputManager* input);
    virtual ~Scene();
    
    virtual bool init();
    virtual void release();
    
    virtual void update();
    virtual void draw();
    
    void game(Game* parent);
    void videoManager(VideoManager* video);
    void inputManager(InputManager* input);
    
    bool active() const;
    
    void addLayer(Layer* layer);
    
private:
    Scene(const Scene&);
    const Scene& operator=(const Scene&);
    
    bool _active;
    
    Game* _game;
    VideoManager* _video;
    InputManager* _input;
    
    std::vector<Layer*> _layers;
};

#endif	/* SCENE_H */

