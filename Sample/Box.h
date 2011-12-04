#ifndef BOX_H
#define	BOX_H

#include "Vector.h"

class Box {
public:
    Box(const Vector& position, const Vector& size);
    virtual ~Box();

    virtual bool collides(const Box& other);
    
protected:
    void position(const Vector& dest);
    void move(const Vector& delta);
    
private:
    Vector _position;
    // the boundings of the body, 0 = top left, 1 = bottom right
    Vector _boundings[2];
    
};

#endif	/* BOX_H */

