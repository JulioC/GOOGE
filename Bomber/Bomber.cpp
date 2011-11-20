#include "Bomber.h"
#include <iostream>

#include "Level.h"

Bomber::Bomber():
Game() {
    
}

Bomber::~Bomber() {
}

void Bomber::setup() {
    Game::setup();

    Scene* level = new Level(this);
    setNextScene(level);
}
