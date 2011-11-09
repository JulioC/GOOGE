#ifndef SCENE_H
#define	SCENE_H

#include <vector>

#include "defs.h"

#include "InputManager.h"
#include "VideoManager.h"
#include "Layer.h"

class Game;

class Scene: public Object {
public:
    Scene(Game* game);
    virtual ~Scene();
    
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

