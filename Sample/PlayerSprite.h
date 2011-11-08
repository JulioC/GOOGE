#ifndef PLAYERSPRITE_H
#define PLAYERSPRITE_H

#include "Sprite.h"

class PlayerSprite : public Sprite {
public:
    PlayerSprite(Game* game, Vector position);
    virtual ~PlayerSprite();
    
    void update();

private:
    PlayerSprite(const PlayerSprite&);
    const PlayerSprite& operator=(const PlayerSprite&);
    
    float _speed;

};

#endif  /* PLAYERSPRITE_H */

