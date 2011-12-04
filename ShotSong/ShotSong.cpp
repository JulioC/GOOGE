#include "ShotSong.h"
#include "FirstLevel.h"

ShotSong::ShotSong() {
}

ShotSong::~ShotSong() {
}

void ShotSong::setup() {
    Game::setup();
    
    Scene* firstLevel = new FirstLevel(this);
    setNextScene(firstLevel);
}
