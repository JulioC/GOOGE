#include "PlayerSprite.h"
#include "Game.h"

PlayerSprite::PlayerSprite(Game* game, Vector position) : 
Sprite(game, "Player.png", position), 
_speed(0.4f) {
    
}

PlayerSprite::~PlayerSprite() {
}

void PlayerSprite::update() {
    InputManager* input = _game->input();
    Vector posMod(0, 0);
    
    if(input->keyDown(SDLK_UP)) {
        posMod += Vector(0, -_speed);
    }
    
    if(input->keyDown(SDLK_DOWN)) {       
        posMod += Vector(0, _speed);
    }
    
    if(input->keyDown(SDLK_RIGHT)) {
        posMod += Vector(_speed, 0);
    }
    
    if(input->keyDown(SDLK_LEFT)) {
        posMod += Vector(-_speed, 0);
    }
    
    _position += posMod;
}
