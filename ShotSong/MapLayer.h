#ifndef MAPLAYER_H
#define MAPLAYER_H

#include "Layer.h"
#include "PlayerSprite.h"

class MapLayer: public Layer {
public:
    MapLayer(Game* game);
    virtual ~MapLayer();
    
    void update();
    void draw();
    std::vector<Box*>boxes;

private:
    MapLayer(const MapLayer&);
    const MapLayer& operator=(const MapLayer&);
    PlayerSprite* player;
    int coins;

};

#endif  /* MAPLAYER_H */

