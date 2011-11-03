#include "Bomber.h"
#include "Intro.h"

Bomber::Bomber() {
}

Bomber::~Bomber() {
}

bool Bomber::setup() {
    if(!Game::setup()) {
        return false;
    }
    
    this->setNextScene(new Intro());
}
