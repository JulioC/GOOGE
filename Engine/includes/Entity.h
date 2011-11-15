#ifndef ENTITY_H
#define	ENTITY_H

#include "defs.h"
#include "Object.h"

class Game;

class Entity: public Object {
public:
    Entity(Game* game):
    _ended(0),
    _game(game) {
    }
    virtual ~Entity() {        
    }
    
    virtual void update() = 0;
    virtual void draw() = 0;

    bool ended() const {
        return _ended;
    }
    
protected:
    bool _ended;
    Game* _game;
    
private:
    Entity(const Entity&);
    const Entity& operator=(const Entity&);
    
};

#endif	/* ENTITY_H */

