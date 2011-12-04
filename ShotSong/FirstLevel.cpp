#include "FirstLevel.h"
#include "MapLayer.h"

FirstLevel::FirstLevel(Game* game):
Level(game) {
    Layer* mapLayer = new MapLayer(_game);
    addLayer(mapLayer);
}

FirstLevel::~FirstLevel() {
}

