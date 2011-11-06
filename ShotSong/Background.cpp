#include "Background.h"
#include "Vector.h"

Background::Background() {
}

Background::~Background() {
}

void Background::update() {
    if(_temp == false) {
        Vector vectortest(0,0);
        Sprite* test = new Sprite("background.png", vectortest);
        addSprite(test);
        _temp = true;
    }
}