#ifndef PLAYER_H
#define	PLAYER_H

#include "Sprite.h"

class Vector;

class Player : public Sprite {
public:
    Player();
    virtual ~Player();
    
    void update();
    
private:
    Player(const Player& orig);

};

#endif	/* PLAYER_H */

