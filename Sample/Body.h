#ifndef BODY_H
#define	BODY_H

#include "Sprite.h"
#include "Box.h"

class Body: public Sprite, Box {
public:
    Body();
    virtual ~Body();
        
private:
    Body(const Body&);
    const Body& operator=(const Body&);

};

#endif	/* BODY_H */

