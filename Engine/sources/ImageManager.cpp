#include "ImageManager.h"

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

char* ImageManager::identify(Image* obj) {
    const char* filename = obj->filename();
    char* identifier = new char[sizeof(filename)];
    strcpy(identifier, filename);
    
    return identifier;
}
