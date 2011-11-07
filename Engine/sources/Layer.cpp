#include "Layer.h"
#include "Sprite.h"
#include "Log.h"

Layer::Layer(Game* game):
_game(game) {
}

Layer::~Layer() {
}

void Layer::update() {
    for(std::vector<Sprite*>::size_type i=0;i<_sprites.size();i++) {
        if(_sprites[i]->terminate()) {
            removeSprite(i);
        }
        else {
            _sprites[i]->update();
        }
    }
}

void Layer::draw() {
    for(std::vector<Sprite*>::size_type i=0;i<_sprites.size();i++) {
        _sprites[i]->draw();
    }
}

void Layer::addSprite(Sprite* sprite) {
    if(sprite != NULL) {
        std::vector<Sprite*>::size_type i = nextIndex();
        if(i == _sprites.size()) {
            _sprites.push_back(sprite);
        }
        else {
            _sprites[i] = sprite;
        }
    }
    else {
        Log::error("Tried to add a null sprite", this);
    }
}

void Layer::removeSprite(int index) {
    _sprites[index] = NULL;
}

int Layer::nextIndex() const {
    std::vector<Sprite*>::size_type i;
    for(i=0;i<_sprites.size();i++) {
        if(_sprites[i] == NULL) {
            return i;
        }
    }
    return i;
}
