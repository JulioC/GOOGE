#include "Font.h"

Font::Font(SDL_Surface* screen, const char* filename, int size):
_filename(NULL),
_size(size),
_screen(screen),
_font(NULL) {
    size_t len = strlen(filename);
    
    _filename = new char[len + 1];
    strcpy(_filename, filename);
    
    _font = TTF_OpenFont(_filename, _size);
    if(_font == NULL) {
        throw load_error();
    }
}

Font::~Font() {
    if(_filename != NULL) {
        delete[] _filename;
    }
    if(_font != NULL) {
        TTF_CloseFont(_font);
    }
}

const char* Font::filename() const {
    return _filename;
}

int Font::size() const {
    return _size;
}