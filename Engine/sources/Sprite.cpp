#include "Sprite.h"

#include <cmath>

#include "Game.h"
#include "VideoManager.h"

Sprite::Sprite(Game* game, const char* filename, const Vector& position):
Entity(game),
_image(NULL), 
_position(position),
_cols(0),
_rows(0),
_currentFrame(0, 0),
_frameSize(0, 0) {
    _image = _game->video()->images()->get(filename);
    _cols = 1;
    _rows = 1;
    _frameSize = _image->size();
}

Sprite::Sprite(Game* game, const char* filename, const Vector& position, const Vector& frameSize):
Entity(game),
_image(NULL), 
_position(position),
_cols(0),
_rows(0),
_currentFrame(0, 0),
_frameSize(frameSize) {
    _image = _game->video()->images()->get(filename);
    
    _frameSize.floor();
    
    _cols = floor(_image->width() / _frameSize.x());
    _rows = floor(_image->height() / _frameSize.y());
}

Sprite::~Sprite() {
    _game->video()->images()->release(_image);
}

void Sprite::update() {
}

void Sprite::draw() {
    _image->draw(_position, _currentFrame, _frameSize);
}

void Sprite::setFrame(int n) {
    int col = n % _cols;
    int row = (n - col) / _cols;
    
    setFrame(col, row);
}

void Sprite::setFrame(int col, int row) {
    col = col % _cols;
    row = row % _rows;

    _currentFrame = Vector(col * _frameSize.x(), row * _frameSize.y()); 
}

int Sprite::frameCount() const {
    return _cols * _rows;
}

int Sprite::colCount() const {
    return _cols;
}

int Sprite::rowCount() const {
    return _rows; 
}

