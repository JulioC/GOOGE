#include "Menu.h"
#include "Background.h"

Menu::Menu(Game* parent, VideoManager* video, InputManager* input):
Scene::Scene(parent, video, input) {
    
}

void Menu::update() {
    if(_temp==false) {
        Background* layert = new Background();
        addLayer(layert);
        _temp = true;
    }
    Scene::update();
}

void Menu::draw() {
    Scene::draw();
}

Menu::~Menu() {
    
}