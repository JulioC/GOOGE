#include <stddef.h>

#include "Game.h"
#include "Log.h"
#include "Scene.h"

Game* Game::_instance = NULL;

Game* Game::instance() {
    if(_instance == NULL) { 
        _instance = new Game();
    }
    
    return _instance;
}

Game::Game():
_video(NULL),
_input(NULL),
_ended(false),
_scenes(),
_activeScenes(),
_currentScene(NULL) {
}

Game::~Game() {
    cleanup();
}

bool Game::setup() {
    if(SDL_Init(0) == -1) {
        Log::error("Unable to initialize the SDL", this);
        Log::error(SDL_GetError(), this);
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
    
    _ended = false;
   
    Log::message("Game setup", this);
 
    return true;
}

void Game::cleanup() {
    // Release any activeScene on the stack
    while(!_activeScenes.empty()) {
        Scene* scene = _activeScenes.top();
        scene->release();
        _activeScenes.pop();
    }
    _currentScene = NULL;
    
    _scenes.clear();
    
    _video->release();
    _video = NULL;
    
    _input->release();
    _input = NULL;
    
    Log::message("Game cleanup", this);
}

void Game::run() {
    _input->update();
    _ended = _input->terminated();
    
    if(_activeScene == NULL) {
        Log::error("No active scene", this);
        _ended = true;
    }
    else {
        _activeScene->update();
        _activeScene->draw();
    }
    
    _video->update();
}

bool Game::ended() const {
    return _ended;
}

