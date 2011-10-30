#include "Image.h"

#include "SDL/SDL_image.h"

Image::Image():
_filename(NULL),
_surface(NULL),
_screen(NULL)
{
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

void Image::screen(SDL_Surface* scr) {
    _screen = scr;
}

bool Image::load(const char* filename) {
    size_t len = strlen(filename);
    
    if(_filename != NULL) {
        delete[] _filename;
    }
    _filename = new char[len];
    strcpy(_filename, filename);
    
    if(_surface != NULL) {
        SDL_FreeSurface(_surface);
        _surface = NULL;
    }
    
    SDL_Surface *image = NULL;
    SDL_Surface *optimized = NULL;
    
    image = IMG_Load(_filename);
    if(image != NULL) {
        optimized = SDL_DisplayFormatAlpha(image);
        SDL_FreeSurface(image);
    }
    
    if(optimized == NULL) {
        return false;
    }
    
    _surface = optimized;
    return true;
}

void Image::draw(const Vector& position) {
    SDL_Rect offset;
    offset.x = position.x();
    offset.y = position.y();
    
    SDL_BlitSurface(_surface, NULL, _screen, &offset);
}

