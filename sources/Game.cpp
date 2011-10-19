#include <stddef.h>

#include "Game.h"
#include "Log.h"

Game* Game::_instance = NULL;

Game* Game::instance() {
    if(_instance == NULL) { 
        _instance = new Game();
    }
    
    return _instance;
}

Game::Game() {
}

Game::~Game() {
}

bool Game::setup() {
    
    Log::message("Game setup", this);
    
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) == -1) {
        Log::error("Unable to initialize the SDL",this);
        return false;
    }
    
    if(!(_videomanager.init(640,480,"Amazing Wonderful Game"))) {
       return false;
    }
    
    return true;
}

void Game::cleanup() {
    
    
    Log::message("Game cleanup", this);
}

void Game::run() {
    
}

bool Game::running() const {
    return !_quit;
}

