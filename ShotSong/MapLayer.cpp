#include <string>

#include "MapLayer.h"
#include "PlayerSprite.h"
#include "CoinSprite.h"
#include "Label.h"

MapLayer::MapLayer(Game* game):
Layer(game), 
coins(0) {
    player = new PlayerSprite(_game, Vector(0, 0));
    addEntity(player);
    
    CoinSprite* c1 = new CoinSprite(_game, Vector(100, 20));
    addEntity(c1);
    boxes.push_back(c1);
    
    CoinSprite* c2 = new CoinSprite(_game, Vector(200, 20));
    addEntity(c2);
    boxes.push_back(c2);
    
    CoinSprite* c3 = new CoinSprite(_game, Vector(20, 200));
    addEntity(c3);
    boxes.push_back(c3);
}

MapLayer::~MapLayer() {
}

void MapLayer::update() {
    Layer::update();
    
    if(player != NULL) {
        for(std::vector<Box*>::size_type i=0;i<boxes.size();i++) {
            if(player->collides(*boxes[i])) {
                coins++;
            }
        }
    }
}

void MapLayer::draw() {
    Label* lblCoins = new Label(_game, "test.otf", 12);
    lblCoins->setPosition(Vector(300, 300));
    
    char* buffer = new char[50];
    sprintf(buffer, "Coins: %d", coins);
    
    lblCoins->setMessage(buffer);
    Color cl = {255, 0, 0};
    lblCoins->setColor(cl);
    
    lblCoins->draw();
    
    Layer::draw();
}
