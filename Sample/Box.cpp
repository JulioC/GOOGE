#include "Box.h"

Box::Box(const Vector& position, const Vector& size):
_position(position) {
    _boundings[0] = position;
    _boundings[1] = position + size;
}

Box::~Box() {
}

bool Box::collides(const Box& other) {
    if(_boundings[1].x() <= other._boundings[0].x()) {
        return false;
    }
    if(other._boundings[1].x() <= _boundings[0].x()) {
        return false;
    }
    if(_boundings[1].y() <= other._boundings[0].y()) {
        return false;
    }
    if(other._boundings[1].y() <= _boundings[0].y()) {
        return false;
    }
    
    return true;
}

void Box::position(const Vector& dest) {
    move(dest - _position); 
}

void Box::move(const Vector& delta) {
    _boundings[0] += delta;
    _boundings[1] += delta;
}