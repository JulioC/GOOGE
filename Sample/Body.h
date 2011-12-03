#ifndef BODY_H
#define	BODY_H

#include "Vector.h"

class Body {
public:
    Body(const Vector& position, const Vector& size);
    virtual ~Body() = 0;

    virtual bool collides(const Body& other);
    
    void moveTo(const Vector& position);
    
protected:
    Vector _position;
    // the boundings of the body, 0 = top left, 1 = bottom right
    Vector _boundings[2];
    
};

#endif	/* BODY_H */

