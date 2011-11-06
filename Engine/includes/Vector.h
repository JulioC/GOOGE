#ifndef VECTOR_H
#define	VECTOR_H

class Vector {
public:
    Vector(float x, float y);
    Vector(const Vector& orig);    
    ~Vector();
    
    const Vector& operator=(const Vector& rh);

    Vector operator+(const Vector& rh) const;
    const Vector& operator+=(const Vector& rh);
    
    Vector operator-(const Vector& rh) const;
    const Vector& operator-=(const Vector& rh);
    
    Vector operator*(const float& rh) const;
    const Vector& operator*=(const float& rh);
    
    Vector operator/(const float& rh) const;
    const Vector& operator/=(const float& rh);
    
    bool operator==(const Vector& rh) const;
    bool operator!=(const Vector& rh) const;
    
    float dotProduct(const Vector& rh) const;
    
    float magnitude() const;
    
    void normalize();
    void floor();
    void ceil();
    
    float x() const;
    float y() const;
    
private:
    float _x;
    float _y;
    
};

#endif	/* VECTOR_H */

