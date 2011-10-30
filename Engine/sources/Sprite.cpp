#include "Sprite.h"
#include "Image.h"
#include "Scene.h"
#include "VideoManager.h"

Sprite::Sprite():
_image(NULL), 
_position(0,0),
_terminate(false) {
}

Sprite::Sprite(Image* image, Vector position): 
_image(image), 
_position(position),
_terminate(false) {
}
Sprite::Sprite(const char* filename, Vector position): 
_position(position),
_terminate(false) {
    Image* image = VideoManager::instance()->getImage(filename);
    _image = image;
}

Sprite::~Sprite() {
}

void Sprite::update() {
    
}

void Sprite::draw() {
    _image->draw(_position);
}

bool Sprite::terminate() const {
    return _terminate;
}
