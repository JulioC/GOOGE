#include "Stage.h"
#include "PlayerSprite.h"
#include "Label.h"

Stage::Stage(Game* game) : 
Layer(game) {
    
    Vector initialPos(0,0);
    Sprite* playerSprite = new PlayerSprite(_game, initialPos);
    addEntity(playerSprite);
    
    Label* lbl = new Label(_game, "test.otf", 24);
    lbl->setMessage("Hello World");
    
    Color r = {255, 0, 0};
    lbl->setColor(r);
    addEntity(lbl);
    
}

Stage::~Stage() {
}

