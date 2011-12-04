#include "PlayerSprite.h"
#include "Game.h"

PlayerSprite::PlayerSprite(Game* game, Vector position) : 
Sprite(game, "tiles.jpg", position, Vector(40, 40)), 
_speed(0.4f),
current(0) {
    
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
    
    if(input->keyPressed(SDLK_SPACE)) {
        setFrame(current++);
    }
    
    _position += posMod;
}
