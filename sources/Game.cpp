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

Game::Game(){
}

Game::~Game() {
    cleanup();
}

bool Game::setup() {
    if(SDL_Init(0) == -1) {
        Log::error("Unable to initialize the SDL", this);
        return false;
    }
    
    _videoManager = VideoManager::instance();
    _videoManager->init(640, 480, "Amazing Wonderful Game");
    if(!_videoManager->initiated()) {
       return false;
    }
    
    _inputManager = InputManager::instance();
    _inputManager->init();
    if(!_inputManager->initiated()) {
       return false;
    }
   
    Log::message("Game setup", this);
 
    return true;
}

void Game::cleanup() {
    _videoManager->release();
    _inputManager->release();
    
    Log::message("Game cleanup", this);
}

void Game::run() {
    _inputManager->update();
    
    _quit = _inputManager->terminated();
}

bool Game::running() const {
    return !_quit;
}

