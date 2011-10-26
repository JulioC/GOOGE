#ifndef IMAGE_H
#define	IMAGE_H

#include <SDL/SDL.h>

#include "Vector.h"

class Image {
public:
    explicit Image();
    ~Image();

    const char* filename() const;
    void screen(SDL_Surface* scr);
    
    bool load(const char* filename);
    
    void draw(const Vector& position) ;

private:
    Image(const Image&);
    const Image& operator=(const Image&);

    char* _filename;
    SDL_Surface* _surface;
    
    SDL_Surface* _screen;
};

#endif	/* IMAGE_H */
