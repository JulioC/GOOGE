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
    Scene(Game* parent);
    virtual ~Scene();
    
    virtual bool init();
    virtual void release();
    
    virtual void update();
    virtual void draw();
        
protected:
    void addLayer(Layer* layer);
    
private:
    Scene(const Scene&);
    const Scene& operator=(const Scene&);
        
    Game* _game;
    VideoManager* _video;
    InputManager* _input;
    
    std::vector<Layer*> _layers;
};

#endif	/* SCENE_H */

