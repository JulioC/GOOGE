#include "LevelTest.h"

LevelTest::LevelTest(Game* parent) : 
Level::Level(parent) {
}

LevelTest::~LevelTest() {
}

bool LevelTest::init() {
    if(!Level::init()) {
        return false;
    }
    
    return true;
}
