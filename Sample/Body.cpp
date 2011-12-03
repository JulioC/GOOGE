#include "Body.h"

Body::Body(const Vector& position, const Vector& size):
_position(position) {
    _boundings[0] = position;
    _boundings[1] = position + size;
}

bool Body::collides(const Body& other) {
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

void Body::moveTo(const Vector& position) {
    Vector delta = position - _position; 
    _boundings[0] += delta;
    _boundings[1] += delta;
}