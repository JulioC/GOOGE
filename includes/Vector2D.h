#ifndef VECTOR2D_H
#define	VECTOR2D_H

class Vector2D {
public:
    Vector2D(float x, float y): 
    _x(x),
    _y(y) {
        
    };
    ~Vector2D() {

    }
    
    // @TODO: Implement vector operations 

    float x, y;
    
private:
    Vector2D(const Vector2D& orig);
    const Vector2D& operator=(const Vector2D& orig);

};

#endif	/* VECTOR2D_H */

