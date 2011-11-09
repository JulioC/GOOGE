#include "Image.h"

Image::Image(SDL_Surface* screen, const char* filename):
Surface(screen),
_filename(NULL) {
    size_t len = strlen(filename);
    
    _filename = new char[len];
    strcpy(_filename, filename);
    
    SDL_Surface *image = NULL;
    SDL_Surface *optimized = NULL;
    
    image = IMG_Load(_filename);
    if(image == NULL) {
        throw load_error();
    }

    optimized = SDL_DisplayFormatAlpha(image);
    SDL_FreeSurface(image);
    if(optimized == NULL) {
        throw load_error();
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

