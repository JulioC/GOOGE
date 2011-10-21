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
    
    float dotProduct(const Vector& rh);
    
    void normalize();
    float magnitude();
    
    float x() const;
    float y() const;
    
    // @TODO: Implement vector operations 
    
private:
    float _x;
    float _y;
    
};

#endif	/* VECTOR_H */

