#ifndef SPRITE_H
#define	SPRITE_H

#include "defs.h"
#include "Entity.h"
#include "Image.h"

class Sprite: public Entity {
public:
    Sprite(Game* game, const char* filename, const Vector& position);
    Sprite(Game* game, const char* filename, const Vector& position, const Vector& frameSize);
    virtual ~Sprite();

    virtual void update();
    virtual void draw();

protected:
    Image* _image;
    Vector _position;

private:    
    Sprite(const Sprite&);
    const Sprite& operator=(const Sprite&);
    
    Vector _frameSize;
    

};

#endif	/* SPRITE_H */

