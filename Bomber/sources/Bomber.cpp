#include "Bomber.h"
#include "Intro.h"
#include <iostream>

Bomber::Bomber():
Game() {
}

Bomber::~Bomber() {
}

bool Bomber::setup() {
    if(!Game::setup()) {
        return false;
    }

    //this->setNextScene(new Intro());
    
    return true;
}
