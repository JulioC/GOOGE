#include "Level.h"

#include "Stage.h" 

Level::Level(Game* game):
Scene(game) {
    Layer* stage = new Stage(_game);
    addLayer(stage);
}

Level::~Level() {
}