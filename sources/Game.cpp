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

