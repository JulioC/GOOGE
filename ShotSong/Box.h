#ifndef BOX_H
#define	BOX_H

#include "Vector.h"
#include "Sprite.h"

class Box: public Sprite {
public:
    Box(Game* game, const char* filename, const Vector& position, const Vector& size);
    Box(Game* game, const char* filename, const Vector& position, const Vector& size, const Vector& framesize);
    virtual ~Box();

    virtual bool collides(const Box& other);
    
protected:
    void position(const Vector& dest);
    void move(const Vector& delta);
    
private:
    // the boundings of the body, 0 = top left, 1 = bottom right
    Vector _boundings[2];
    
};

#endif	/* BOX_H */

