#include "Text.h"

Text::Text(SDL_Surface* screen, SDL_Surface* surface):
Surface(screen) {
    _surface = surface;
}

Text::~Text() {
    SDL_FreeSurface(_surface);
}
