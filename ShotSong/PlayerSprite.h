#ifndef PLAYERSPRITE_H
#define PLAYERSPRITE_H

#include "Box.h"

class PlayerSprite : public Box {
public:
    PlayerSprite(Game* game, Vector position);
    virtual ~PlayerSprite();
    
    void update();
    void draw();

private:
    PlayerSprite(const PlayerSprite&);
    const PlayerSprite& operator=(const PlayerSprite&);
    
    float _speed;
    
    enum frameDir {
        FRAMEUP, 
        FRAMERIGHT,
        FRAMEDOWN,
        FRAMELEFT
    };
    
    frameDir playerDir;
    
    int currentFrame;
    int frameTimer;

};

#endif  /* PLAYERSPRITE_H */
