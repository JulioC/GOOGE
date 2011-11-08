#include "ShotSong.h"
#include "LevelTest.h"

ShotSong::ShotSong() {
    
}

ShotSong::~ShotSong() {
    
}

bool ShotSong::setup() {
    if(!Game::setup()) {
        return false;
    }
    
    setTitle("Shot Song");
    
    Scene* leveltest = new LevelTest(this);
    setNextScene(leveltest);
    
    return true;
}