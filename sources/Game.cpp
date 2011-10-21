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
    _scenes.clear();
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
        _activeScene->draw();
    }
    
    _video->update();
}

bool Game::ended() const {
    return _ended;
}

int Game::addScene(Scene* scene) {
    int index = _scenes.size();
    _scenes.push_back(scene);
    return index;
}

bool Game::removeScene(int index) {
    if(index >= _scenes.size()) {
        Log::error("Tried to remove invalid scene", this);
        return false;
    }
    
    Scene* scene = _scenes[index];
    if(scene == _activeScene) {
        Log::error("Tried to remove active scene", this);
        return false;
    }
    
    // @TODO: track unused indexes to re-use
    _scenes[index] = NULL;
    
    return true;
}

bool Game::activateScene(int index) {
    if(index >= _scenes.size()) {
        Log::error("Tried to active invalid scene", this);
        return false;
    }
    
    Scene* scene = _scenes[index];
    
    if(scene == NULL) {
        Log::error("Tried to active null scene", this);
        return false;
    }
    
    // If already active, we shouldn't be calling for its activation
    if(scene->active()) {
        Log::error("Tried to re-active scene", this);
        return false;
    }
    
    if(!scene->init()) {
        Log::error("Failed to initialize scene", this);
        return false;
    }
    
    _activeScene->release();

    _activeScene = scene;
    
    return true;
}

void Game::setTitle(const char* title) {
    SDL_WM_SetCaption(title, NULL);
}