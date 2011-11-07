#ifndef MAP_H
#define	MAP_H

#include "Layer.h"

class Map : public Layer {
public:
    Map();
    virtual ~Map();
    
private:
    Map(const Map&);
    
};

#endif	/* MAP_H */

