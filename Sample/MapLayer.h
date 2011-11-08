#ifndef MAPLAYER_H
#define MAPLAYER_H

#include "Layer.h"

class MapLayer : public Layer {
public:
    MapLayer(Game* game);
    virtual ~MapLayer();

private:
    MapLayer(const MapLayer&);
    const MapLayer& operator=(const MapLayer&);

};

#endif  /* MAPLAYER_H */

