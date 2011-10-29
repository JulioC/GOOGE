#include "ShotSong.h"
#include "Menu.h"

ShotSong::ShotSong() {
    
}

ShotSong::~ShotSong() {
    
}

bool ShotSong::setup() {
    Game::setup();
    setTitle("Shot Song");
    _gameState = 1;
    _stateLoaded = false;
    return true;
}

void ShotSong::run() {
    if(_stateLoaded == false) {
        if(_gameState == 1) {
            Menu* menu = new Menu(this, VideoManager::instance(), InputManager::instance());
            setNextScene(menu);
            _stateLoaded = true;
        }
    }
    Game::run();
}