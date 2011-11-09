#include "FirstScene.h"
#include "MapLayer.h"

FirstScene::FirstScene(Game* game) : 
Scene(game) {
    
    Layer* mapLayer = new MapLayer(_game);
    addLayer(mapLayer);
    
}

FirstScene::~FirstScene() {
}

