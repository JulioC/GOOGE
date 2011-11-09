#include "Sprite.h"
#include "VideoManager.h"
#include "Game.h"

Sprite::Sprite(Game* game, const char* filename, const Vector& position):
_game(game),
_image(NULL), 
_position(position) {
    _image = _game->video()->images()->get(filename);
}

Sprite::~Sprite() {
    _game->video()->images()->release(&_image);
}

void Sprite::update() {

}

void Sprite::draw() {
    _image->draw(_position);
}
