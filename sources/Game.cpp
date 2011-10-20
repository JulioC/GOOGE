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

Game::Game():
_video(NULL),
_input(NULL) {
}

Game::~Game() {
    cleanup();
}

bool Game::setup() {
    if(SDL_Init(0) == -1) {
        Log::error("Unable to initialize the SDL", this);
        return false;
    }
    
    _video = VideoManager::instance();
    _video->init(640, 480, "Amazing Wonderful Game");
    if(!_video->initiated()) {
       return false;
    }
    
    _input = InputManager::instance();
    _input->init();
    if(!_input->initiated()) {
       return false;
    }
   
    Log::message("Game setup", this);
 
    return true;
}

void Game::cleanup() {
    _video->release();
    _input->release();
    
    Log::message("Game cleanup", this);
}

void Game::run() {
    _input->update();
    
    _quit = _input->terminated();
}

bool Game::running() const {
    return !_quit;
}

