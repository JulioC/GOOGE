#include "ImageManager.h"
#include "Image.h"

ImageManager::ImageManager(SDL_Surface* screen):
ResourceManager(),
_screen(screen) {
}

ImageManager::~ImageManager() {
}

Image* ImageManager::load(const char* identifier) {
    Image* img = new Image();
    if(!img->load(identifier)) {
        delete img;
        return NULL;
    }
    img->screen(_screen);
    return img;
}

std::string ImageManager::identify(Image* obj) {
    return std::string(obj->filename());
}
