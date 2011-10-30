#include <vector>

#include "Scene.h"
#include "Log.h"
#include "Layer.h"

Scene::Scene():
_game(NULL),
_video(NULL),
_input(NULL),
_active(false) {
}

Scene::Scene(Game* parent, VideoManager* video, InputManager* input):
_game(parent),
_video(video),
_input(input),
_active(false) {
}

Scene::~Scene() {
}

bool Scene::init() {
    if(_game == NULL) {
        Log::error("No Game set", this);
        return false;
    }
    if(_video == NULL) {
        Log::error("No VideoManager set", this);
        return false;
    }
    if(_input == NULL) {
        Log::error("No InputManager set", this);
        return false;
    }
    
    // @TODO: Init general scene stuff (layers, elements, etc)
    
    _active = true;
    
    return true;
}

void Scene::release() {
}

void Scene::game(Game* parent) {
    _game = parent;
}

void Scene::videoManager(VideoManager* video) {
    _video = video;
}

void Scene::inputManager(InputManager* input) {
    _input = input;
}

bool Scene::active() const {
    return _active;
}

void Scene::addLayer(Layer* layer) {
    if(layer != NULL) {
        _layers.push_back(layer);
    }
    else {
        Log::error("Tried to add a null layer", this);
    }
}

void Scene::update() {
    for(std::vector<Layer*>::size_type i=0;i<_layers.size();i++) {
        _layers[i]->update();
    }
}

void Scene::draw() {
    for(std::vector<Layer*>::size_type i=0;i<_layers.size();i++) {
        _layers[i]->draw();
    }
}
