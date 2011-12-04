#ifndef COINSPRITE_H
#define COINSPRITE_H

#include "Box.h"

class CoinSprite: public Box {
public:
    CoinSprite(Game* game, Vector position);
    virtual ~CoinSprite();

private:
    CoinSprite(const CoinSprite&);
    const CoinSprite& operator=(const CoinSprite&);

};

#endif  /* COINSPRITE_H */

