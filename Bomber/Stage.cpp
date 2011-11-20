#include "Stage.h"
#include "Tile.h"

Stage::Stage(Game* game):
Layer(game) {
    Sprite* tile1 = new Tile(_game, Vector(0, 0));
    addEntity(tile1);
}

Stage::~Stage() {
}
