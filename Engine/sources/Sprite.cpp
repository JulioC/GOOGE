#include "Sprite.h"

#include "Game.h"
#include "VideoManager.h"

Sprite::Sprite(Game* game, const char* filename, const Vector& position):
_game(game),
_image(NULL), 
_position(position),
_frameSize(0, 0) {
    _image = _game->video()->images()->get(filename);
    _frameSize = _image->size();
}

Sprite::Sprite(Game* game, const char* filename, const Vector& position, const Vector& frameSize):
_game(game),
_image(NULL), 
_position(position),
_frameSize(frameSize) {
    _image = _game->video()->images()->get(filename);
}

Sprite::~Sprite() {
    _game->video()->images()->release(_image);
}

void Sprite::update() {

}

void Sprite::draw() {
    _image->draw(_position);
}
