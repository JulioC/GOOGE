#ifndef SURFACE_H
#define	SURFACE_H

#include "defs.h"
#include "Object.h"

class Surface: public Object {
public:
    Surface(SDL_Surface* screen);
    virtual ~Surface();

    void draw(const Vector& position);
    //@TODO: implement draw() variants

protected:
    SDL_Surface* _surface;

private:
    Surface(const Surface&);
    const Surface& operator=(const Surface&);

    SDL_Surface* _screen;

};

#endif	/* SURFACE_H */

