#include "Level.h"

#include "VideoManager.h"
#include "InputManager.h"
#include "Background.h"

Level::Level(Game* parent) :
Scene::Scene(parent, VideoManager::instance(), InputManager::instance()) {
}

Level::~Level() {
    
}

bool Level::init() {
    if(!Scene::init()) {
        return false;
    }
    
    Layer* background = new Background()
    
    return true;
    
}