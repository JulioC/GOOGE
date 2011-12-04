#include "PlayerSprite.h"
#include "Game.h"

PlayerSprite::PlayerSprite(Game* game, Vector position) : 
Sprite(game, "./contents/warrior.png", position, Vector(28, 38)), 
_speed(0.4f),
currentFrame(0) {
    setFrame(0, 2);
}

PlayerSprite::~PlayerSprite() {
}

void PlayerSprite::update() {
    InputManager* input = _game->input();
    Vector posMod(0, 0);
    
    if(input->keyDown(SDLK_UP)) {
        posMod += Vector(0, -_speed);
        playerDir = FRAMEUP;
    }
    
    else if(input->keyDown(SDLK_DOWN)) {       
        posMod += Vector(0, _speed);
        playerDir = FRAMEDOWN;
    }
    
    else if(input->keyDown(SDLK_RIGHT)) {
        posMod += Vector(_speed, 0);
        playerDir = FRAMERIGHT;
    }
    
    else if(input->keyDown(SDLK_LEFT)) {
        posMod += Vector(-_speed, 0);
        playerDir = FRAMELEFT;
    }
    
    if(posMod != Vector(0, 0)) {
        if(currentFrame==3) {
            currentFrame=0;
        }
        else {
            currentFrame++;
        }
    }
    _position += posMod;
}

void PlayerSprite::draw() {
    setFrame(currentFrame, playerDir);
    
    Sprite::draw();
}
