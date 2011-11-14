#include "Sample.h"
#include "FirstScene.h"

Sample::Sample() {
}

Sample::~Sample() {
}

void Sample::setup() {
    Game::setup();
    
    Scene* firstScene = new FirstScene(this);
    Game::setNextScene(firstScene);
    
}
