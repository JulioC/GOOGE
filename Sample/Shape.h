#ifndef SHAPE_H
#define	SHAPE_H

#include "Vector.h"

class Shape {
public:
    Shape(const Vector& position);
    virtual ~Shape() = 0;

    virtual bool collides(const Shape& other) const = 0;
    
    void move(const Vector& position);
    
protected:
    virtual bool isInside(const Vector& position) const = 0;
    
    Vector _position;
};

#endif	/* SHAPE_H */

