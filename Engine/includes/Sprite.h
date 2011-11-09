#ifndef SPRITE_H
#define	SPRITE_H

#include "defs.h"

#include "Entity.h"
#include "Image.h"
#include "Vector.h"

class Game;

class Sprite: public Entity {
public:
    Sprite(Game* game, const char* filename, const Vector& position);
    virtual ~Sprite();

    virtual void update();
    virtual void draw();

protected:
    Vector _position;
    Image* _image;
    
private:    
    Sprite(const Sprite&);
    const Sprite& operator=(const Sprite&);
    
    Game* _game;

};

#endif	/* SPRITE_H */

