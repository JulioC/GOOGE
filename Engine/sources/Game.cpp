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
_activeScene(NULL) {
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
    if(!_video->init(640, 480, "GOOGE Game")) {
        Log::error("Failed to initialize VideoManager", this);
        return false;
    }
    
    _input = InputManager::instance();
    if(!_input->init()) {
        Log::error("Failed to initialize InputManager", this);
        return false;
    }
    
    _ended = false;
   
    Log::message("Game setup", this);
 
    return true;
}

void Game::cleanup() {   
    _activeScene = NULL;
    
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
    
        if(_nextScene == NULL) {
            _activeScene->draw();
        }
        else {
            if(!activeScene(_nextScene)) {
                Log::error("Failed to change scene", this);
                _ended = true;
            }
        }

        _video->update();
    }
}

bool Game::ended() const {
    return _ended;
}

bool Game::activeScene(Scene* scene) {
    if(scene == NULL) {
        Log::error("Tried to active null scene", this);
        return false;
    }
    
    if(!scene->init()) {
        Log::error("Failed to initialize scene", this);
        return false;
    }
    
    if(_activeScene != NULL) {
        _activeScene->release();
        delete _activeScene;
    }

    _activeScene = scene;
    _nextScene = NULL;
    
    return true;
}

void Game::setNextScene(Scene* scene) {
    _nextScene = scene;
}

void Game::setTitle(const char* title) {
    SDL_WM_SetCaption(title, NULL);
}