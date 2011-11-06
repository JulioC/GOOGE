#ifndef BACKGROUND_H
#define	BACKGROUND_H

#include "Layer.h"

class Background : public Layer {
public:
    Background();
    
    void update();
    
private:
    Background(const Background& orig);
    virtual ~Background();
    
    bool _temp;

};

#endif	/* BACKGROUND_H */

