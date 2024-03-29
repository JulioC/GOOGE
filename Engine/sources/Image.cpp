#include "Image.h"

Image::Image(SDL_Surface* screen, const char* filename):
Surface(screen),
_filename(NULL) {    
    _filename = new char[sizeof(filename)];
    strcpy(_filename, filename);
    
    SDL_Surface *image = NULL;
    SDL_Surface *optimized = NULL;
    
    image = IMG_Load(_filename);
    if(image == NULL) {
        throw LoadException("Unable to load image");
    }

    optimized = SDL_DisplayFormatAlpha(image);
    SDL_FreeSurface(image);
    if(optimized == NULL) {
        throw LoadException("Unable to optimize image");
    }
    
    _surface = optimized;
}

Image::~Image() {
    if(_filename != NULL) {
        delete[] _filename;
    }
    if(_surface != NULL) {
        SDL_FreeSurface(_surface);
    }
}

const char* Image::filename() const {
    return _filename;
}