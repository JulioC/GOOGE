#include "Sprite.h"
#include "VideoManager.h"
#include "Game.h"

Sprite::Sprite(Game* game, const char* filename, const Vector& position):
_terminate(false),
_game(game),
_image(NULL), 
_position(position) {
    _image = _game->video()->getImage(filename);
}

Sprite::~Sprite() {
    _game->video()->releaseImage(&_image);
}

void Sprite::update() {

}

void Sprite::draw() {
    _image->draw(_position);
}

bool Sprite::terminate() const {
    return _terminate;
}
