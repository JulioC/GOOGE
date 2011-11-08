#ifndef BACKGROUND_H
#define	BACKGROUND_H

#include "Layer.h"

class Background : public Layer {
public:
    Background();
    
private:
    Background(const Background& orig);
    virtual ~Background();

};

#endif	/* BACKGROUND_H */

