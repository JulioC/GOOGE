#include <vector>

#include "Scene.h"
#include "Log.h"

Scene::Scene(Game* game):
_game(game),
_layers() {
}

Scene::~Scene() {
    for(int i = 0; i <_layers.size(); i++) {
        if(_layers[i] != NULL) {
            delete _layers[i];
        }
    }
}

void Scene::update() {
    for(int i = 0; i <_layers.size(); i++) {
        if(_layers[i] != NULL) {
            _layers[i]->update();
        }
    }
}

void Scene::draw() {
    for(int i = 0; i <_layers.size(); i++) {
        if(_layers[i] != NULL) {
            _layers[i]->draw();
        }
    }
}

void Scene::addLayer(Layer* layer) {
    if(layer == NULL) {
        Log::error("Tried to add a null layer", this);
    }
    else {
        _layers.push_back(layer);
    }
}
