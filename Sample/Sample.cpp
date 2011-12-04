#include "Sample.h"
#include "Level.h"

Sample::Sample() {
}

Sample::~Sample() {
}

void Sample::setup() {
    Game::setup();
    
    Scene* level = new Level(this);
    setNextScene(level);
    
}
