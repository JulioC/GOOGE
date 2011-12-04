#ifndef TILE_H
#define	TILE_H

#include "Sprite.h"

class Tile: public Sprite {
public:
    Tile(Game* game, const Vector& position);
    virtual ~Tile();

private:
    Tile(const Tile&);
    const Tile& operator=(const Tile&);

};

#endif	/* TILE_H */

