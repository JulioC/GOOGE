#ifndef SHOTSONG_H
#define SHOTSONG_H

#include "Game.h"

class ShotSong: public Game {
public:
    ShotSong();
    virtual ~ShotSong();
    
    void setup();

private:
    ShotSong(const ShotSong&);
    const ShotSong& operator=(const ShotSong&);

};

#endif  /* SHOTSONG_H */

