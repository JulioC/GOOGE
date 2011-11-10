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

Text* Font::render(const char* str, Color color, bool blended) {
    SDL_Surface* surface = NULL;
    
    if(blended) {
        surface = TTF_RenderText_Blended(_font, str, color);
    }
    else {
        surface = TTF_RenderText_Solid(_font, str, color);
    }

    if(surface == NULL) {
        throw load_error();
    }
    
    Text* text = new Text(_screen, surface);
    if(text == NULL) {
        throw load_error();
    }
    
    return text;
}
