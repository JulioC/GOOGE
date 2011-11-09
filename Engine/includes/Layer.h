#ifndef LAYER_H
#define	LAYER_H

#include <vector>
#include <stack>

#include "defs.h"
#include "Object.h"
#include "Entity.h"


class Game;

class Layer: public Object {
public:
    Layer(Game* game);
    virtual ~Layer();
    
    virtual void update();
    virtual void draw();
    
    int addEntity(Entity* entity);
    
protected:
    void removeEntity(int index);
    
    Game* _game;
    
private:
    Layer(const Layer&);
    const Layer& operator=(const Layer&);
    
    std::vector<Entity*> _entities;
    std::stack<int> _indexes;

};

#endif	/* LAYER_H */

