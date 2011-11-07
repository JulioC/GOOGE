#include "Background.h"
#include "Vector.h"

Background::Background() {
    
    Vector vectortest(0,0);
    Sprite* test = new Sprite("background.png", vectortest);
    addSprite(test);
    
}

Background::~Background() {
}
