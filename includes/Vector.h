#ifndef VECTOR_H
#define	VECTOR_H

class Vector {
public:
    Vector(float x, float y): 
    _x(x),
    _y(y) {
        
    };
    ~Vector() {

    }
    
    // @TODO: Implement vector operations 

    float _x, _y;
    
private:
    Vector(const Vector&);
    const Vector& operator=(const Vector&);

};

#endif	/* VECTOR_H */

