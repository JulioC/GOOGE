#include "Surface.h"

Surface::Surface(SDL_Surface* screen):
_screen(screen),
_surface(NULL) {
}

Surface::~Surface() {
}

void Surface::draw(const Vector& position) {
    SDL_Rect offset;
    offset.x = position.x();
    offset.y = position.y();
    
    SDL_BlitSurface(_surface, NULL, _screen, &offset);
}

