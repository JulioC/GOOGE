#ifndef SHOTSONG_H
#define	SHOTSONG_H
#include "Game.h"

class ShotSong : public Game {
public:
    ShotSong();
    bool setup();
    void run();

private:
    ShotSong(const ShotSong& orig);
    virtual ~ShotSong();
    
    int _gameState;
    bool _stateLoaded;
};

#endif	/* SHOTSONG_H */

