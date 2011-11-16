#ifndef SURFACE_H
#define	SURFACE_H

#include "defs.h"
#include "Object.h"

class Surface: public Object {
public:
    Surface(SDL_Surface* screen);
    virtual ~Surface();

    void draw(const Vector& position);
    void draw(const Vector& position, const Vector& clip_position, const Vector& clip_size);

    int width() const;
    int height() const;
    Vector size() const;
    
protected:
    SDL_Surface* _surface;

private:
    Surface(const Surface&);
    const Surface& operator=(const Surface&);

    SDL_Surface* _screen;

};

#endif	/* SURFACE_H */