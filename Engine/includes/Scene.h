#ifndef SCENE_H
#define	SCENE_H

#include <vector>

#include "Object.h"
#include "VideoManager.h"
#include "InputManager.h"
#include "Layer.h"

class Game;

class Scene: public Object {
public:
    Scene(Game* game);
    virtual ~Scene();
    
    virtual bool init();
    virtual void release();
    
    virtual void update();
    virtual void draw();
        
protected:
    void addLayer(Layer* layer);
        
    Game* _game;
    
private:
    Scene(const Scene&);
    const Scene& operator=(const Scene&);
    
    std::vector<Layer*> _layers;
};

#endif	/* SCENE_H */

