#ifndef SPRITE_H
#define	SPRITE_H

#include "Object.h"
#include "Image.h"
#include "Vector.h"

class Sprite : public Object {
public:
    Sprite();
    Sprite(Image* image, Vector position);
    Sprite(const char* filename, Vector position);
    
    virtual void update();
    virtual void draw();
    
    bool terminate() const;
    
protected:
    bool _terminate;
    
    Image* _image;
    Vector _position;
    
private:
    Sprite(const Sprite&);
    virtual ~Sprite();

};

#endif	/* SPRITE_H */

