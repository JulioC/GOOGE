#ifndef SPRITE_H
#define	SPRITE_H

#include "defs.h"
#include "Entity.h"
#include "Image.h"

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

    Game* _game;
    
private:    
    Sprite(const Sprite&);
    const Sprite& operator=(const Sprite&);

};

#endif	/* SPRITE_H */

