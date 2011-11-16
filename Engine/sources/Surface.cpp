#include "Surface.h"

Surface::Surface(SDL_Surface* screen):
_surface(NULL),
_screen(screen) {
}

Surface::~Surface() {
}

void Surface::draw(const Vector& position) {
    SDL_Rect offset;
    offset.x = position.x();
    offset.y = position.y();
    
    SDL_BlitSurface(_surface, NULL, _screen, &offset);
}

void Surface::draw(const Vector& position, const Vector& clip_position, const Vector& clip_size) {
    SDL_Rect offset;
    offset.x = position.x();
    offset.y = position.y();
    
    SDL_Rect clip;
    clip.x = clip_position.x();
    clip.y = clip_position.y();
    clip.w = clip_size.x();
    clip.h = clip_size.y();
    
    SDL_BlitSurface(_surface, &clip, _screen, &offset);
}

int Surface::width() const {
    return _surface->w;
}

int Surface::height() const {
    return _surface->h;
}

Vector Surface::size() const {
    return Vector(_surface->w, _surface->h);
}

