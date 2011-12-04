#include "MapLayer.h"
#include "PlayerSprite.h"

MapLayer::MapLayer(Game* game):
Layer(game) {
    Sprite* playerSprite = new PlayerSprite(_game, Vector(0, 0));
    addEntity(playerSprite);
}

MapLayer::~MapLayer() {
}

