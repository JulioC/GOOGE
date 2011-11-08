#include "Level.h"
#include "Background.h"

Level::Level(Game* parent) :
Scene::Scene(parent) {
}

Level::~Level() {
    
}

bool Level::init() {
    if(!Scene::init()) {
        return false;
    }
    
    Layer* background = new Background();
    addLayer(background);
    
    
    return true;
    
}