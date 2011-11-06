#ifndef SHOTSONG_H
#define	SHOTSONG_H
#include "Game.h"

class ShotSong : public Game {
public:
    ShotSong();
    bool setup();

private:
    ShotSong(const ShotSong& orig);
    virtual ~ShotSong();
    
};

#endif	/* SHOTSONG_H */

