#include "Object.h"

unsigned int Object::_nextid = 0;

Object::Object():
_id(_nextid++) {
    
}

Object::~Object() {
    
}

unsigned int Object::id() const {
    return _id;
}
