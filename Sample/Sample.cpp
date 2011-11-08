#include "Sample.h"
#include "FirstScene.h"

Sample::Sample() {
}

Sample::~Sample() {
}

bool Sample::setup() {
    
    if(!Game::setup()) {
        return false;
    }
    
    Scene* firstScene = new FirstScene(this);
    Game::setNextScene(firstScene);
    
    return true;
    
}
