#ifndef SPRITE_H
#define	SPRITE_H

#include "Object.h"
#include "Image.h"
#include "Vector.h"

class Game;

class Sprite : public Object {
public:
    Sprite(Game* game, const char* filename, const Vector& position);

    virtual void update();
    virtual void draw();
    
    bool terminate() const;
    
protected:
    bool _terminate;
    
    Game* _game;
    
    Image* _image;
    Vector _position;
    
private:
    Sprite(const Sprite&);
    virtual ~Sprite();

};

#endif	/* SPRITE_H */

