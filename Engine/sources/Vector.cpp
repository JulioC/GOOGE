#include "Vector.h"

Vector::Vector(float x, float y):
_x(x),
_y(y) {
}

Vector::Vector(const Vector& orig):
_x(orig._x),
_y(orig._y) {
}

const Vector& Vector::operator =(const Vector& rh) {
    _x = rh._x;
    _y = rh._y;
    return *this;
}

Vector Vector::operator +(const Vector& rh) const {
    float x = _x + rh._x;
    float y = _y + rh._y;
    return Vector(x, y);
}

const Vector& Vector::operator +=(const Vector& rh) {
    _x += rh._x;
    _y += rh._y;
    return *this;
}

Vector Vector::operator -(const Vector& rh) const {
    float x = _x - rh._x;
    float y = _y - rh._y;
    return Vector(x, y);
}

const Vector& Vector::operator -=(const Vector& rh) {
    _x -= rh._x;
    _y -= rh._y;
    return *this;
}

Vector Vector::operator*(const float& rh) const {
    float x = _x * rh;
    float y = _y * rh;    
    return Vector(x, y);
}

const Vector& Vector::operator *=(const float& rh) {
    _x *= rh;
    _y *= rh;
    return *this;
}

Vector Vector::operator /(const float& rh) const {
    float x = _x / rh;
    float y = _y / rh;
    return Vector(x, y);
}

const Vector& Vector::operator /=(const float& rh) {
    _x /= rh;
    _y /= rh;
    return *this;
}

bool Vector::operator ==(const Vector& rh) const {
    return (_x == rh._x && _y == rh._y);
}

float Vector::dotProduct(const Vector& rh) {
    return (_x*rh._x + _y*rh._y);
}

float Vector::x() const {
    return _x;
}

float Vector::y() const {
    return _y;
}

Vector::~Vector() {
}

