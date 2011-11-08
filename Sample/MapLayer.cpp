#include "MapLayer.h"
#include "PlayerSprite.h"

MapLayer::MapLayer(Game* game) : 
Layer::Layer(game) {
    
    Vector initialPos(0,0);
    Sprite* playerSprite = new PlayerSprite(_game, initialPos);
    addEntity(playerSprite);
    
}

MapLayer::~MapLayer() {
}

