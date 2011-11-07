#include <vector>

#include "Scene.h"
#include "Log.h"

Scene::Scene(Game* game):
_game(game),
_layers() {
}

Scene::~Scene() {
}

bool Scene::init() {
    //@TODO: init layers?
        
    return true;
}

void Scene::release() {
    std::vector<Layer*>::size_type i;
    for(i = 0; i <_layers.size(); i++) {
        if(_layers[i] != NULL) {
            delete _layers[i];
        }
    }
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
    std::vector<Layer*>::size_type i;
    for(i = 0; i <_layers.size(); i++) {
        if(_layers[i] != NULL) {
            _layers[i]->update();
        }
    }
}

void Scene::draw() {
    std::vector<Layer*>::size_type i;
    for(i = 0; i <_layers.size(); i++) {
        if(_layers[i] != NULL) {
            _layers[i]->draw();
        }
    }
}
