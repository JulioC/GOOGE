#include "ImageManager.h"
#include "Image.h"

ImageManager::ImageManager(SDL_Surface* screen):
ResourceManager(),
_screen(screen) {
}

ImageManager::~ImageManager() {
}

Image* ImageManager::load(const char* identifier) {
    Image* img = NULL;
    try{
        img = new Image(_screen, identifier);
    }
    catch(load_error e) {
        Log::error("Error on image load", this);
    }
        
    return img;
}

std::string ImageManager::identify(Image* obj) {
    return std::string(obj->filename());
}
