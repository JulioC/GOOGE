#include "Shape.h"

Shape::Shape(const Vector& position):
_position(position) {
}

void Shape::move(const Vector& position) {
    _position = position;
}