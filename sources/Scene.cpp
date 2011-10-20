#include "Scene.h"

Scene::Scene():
_video(NULL),
_input(NULL) {
}

Scene::Scene(VideoManager* video, InputManager* input):
_video(video),
_input(input) {
}

Scene::~Scene() {
}

bool Scene::init() {
    if(_video == NULL) {
        return false;
    }
    if(_input == NULL) {
        return false;
    }
    
    // @TODO: Init general scene stuff (layers, elements, etc)
    
    return true;
}

void Scene::release() {
}

void Scene::videoManager(VideoManager* video) {
    _video = video;
}

void Scene::inputManager(InputManager* input) {
    _input = input;
}

