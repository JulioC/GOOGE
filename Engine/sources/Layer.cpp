#include "Layer.h"
#include "Sprite.h"
#include "Log.h"

Layer::Layer(Game* game):
_game(game),
_entities(),
_indexes() {
}

Layer::~Layer() {
    for(int i = 0; i < _entities.size(); i++) {
        if(_entities[i] != NULL) {
            delete _entities[i];
        }
    }
}

void Layer::update() {
    for(int i = 0; i < _entities.size(); i++) {
        if(_entities[i] != NULL) {
            if(_entities[i]->ended()) {
                removeEntity(i);
            }
            else {
                _entities[i]->update();
            }
        }
    }
}

void Layer::draw() {
    for(int i = 0; i < _entities.size(); i++) {
        if(_entities[i] != NULL) {
            _entities[i]->draw();
        }
    }
}

int Layer::addEntity(Entity* entity) {
    int index = -1;
    if(entity == NULL) {
        Log::error(this, "Tried to add a null sprite");
    }
    else {
        if(_indexes.empty()) {
            index = _entities.size();
            _entities.push_back(entity);
        }
        else {
            index = _indexes.top();
            _indexes.pop();
            _entities[index] = entity;
        }
    }
    
    return index;
}

void Layer::removeEntity(int index) {
    if(_entities[index] == NULL) {
        delete _entities[index];
        _entities[index] = NULL;
    }
}
