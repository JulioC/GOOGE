#include "CoinSprite.h"

CoinSprite::CoinSprite(Game* game, Vector position):
Box(game, "./contents/coin.png", position, Vector(16, 16)){
    
}

CoinSprite::~CoinSprite() {
}

