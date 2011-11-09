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
    Game* _game;
    
    Image* _image;
    Vector _position;
    
private:
    Sprite(const Sprite&);
    const Sprite& operator=(const Sprite&);

};

#endif	/* SPRITE_H */

