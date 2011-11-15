#include "Game.h"

#include "Scene.h"

Game::Game():
_video(NULL),
_input(NULL),
_time(NULL),
_ended(false),
_activeScene(NULL) {
}

Game::~Game() {
    cleanup();
}

void Game::setup() {
    try {
        if(SDL_Init(0) == -1) {
            throw InitException("Unable to initialize the SDL");
        }
        _video = VideoManager::instance();
        _video->init(640, 480, "GOOGE Game");
    
        _input = InputManager::instance();
        _input->init();
    }
    catch(InitException e) {
        Log::error(this, "%s: %s", e.message(), SDL_GetError());
        throw InitException("Unable to initialize GOOGE");
    }
    
    _time = new TimeHandler();
    
    _ended = false;
   
    Log::message(this, "Game setup");
}

void Game::cleanup() {   
    if(_activeScene != NULL) {        
        delete _activeScene;
        _activeScene = NULL;
    }
    
    if(_nextScene != NULL) {        
        delete _nextScene;
        _nextScene = NULL;
    }
    
    if(_time != NULL) {        
        delete _time;
        _time = NULL;
    }
     
    if(_video != NULL) {
        _video->release();
        _video = NULL;
    }
    
    if(_input != NULL) {
        _input->release();
        _input = NULL;
    }
    
    SDL_Quit();
    
    Log::message(this, "Game cleanup");
}

void Game::run() {
    _input->update();
    _ended = _input->terminated();
    _time->update();
    
    if(_activeScene == NULL) {
        Log::error(this, "No active scene");
        throw Exception("Game failed to run");
    }
    else {
        _activeScene->update();
    
        if(_nextScene == NULL) {
            _activeScene->draw();
        }
        else {
            if(!activeNextScene()) {
                Log::error(this, "Failed to change scene");
                _ended = true;
            }
        }

        _video->update();
    }
}

bool Game::ended() const {
    return _ended;
}

VideoManager* Game::video() const {
    return _video;
}

InputManager* Game::input() const {
    return _input;
}

void Game::setNextScene(Scene* scene) {
    _nextScene = scene;
    
    if(_activeScene == NULL) {
        if(!activeNextScene()) {
            Log::error(this, "Failed to change scene");
            _ended = true;
        }
    }
}

void Game::setTitle(const char* title) {
    SDL_WM_SetCaption(title, NULL);
}

bool Game::activeNextScene() {
    if(_nextScene == NULL) {
        Log::error(this, "Tried to active null scene");
        return false;
    }
    
    if(_activeScene != NULL) {
        delete _activeScene;
    }

    _activeScene = _nextScene;
    _nextScene = NULL;
    
    return true;
}