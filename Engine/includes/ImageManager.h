#ifndef IMAGEMANAGER_H
#define	IMAGEMANAGER_H

#include "defs.h"
#include "Image.h"
#include "ResourceManager.h"

class ImageManager: public ResourceManager<Image> {
public:
    ImageManager(SDL_Surface* screen);
    virtual ~ImageManager();
    
private:
    ImageManager(const ImageManager&);
    const ImageManager& operator=(const ImageManager&);

    Image* load(const char* identifier);
    char* identify(Image* obj);
    
    SDL_Surface* _screen;
};

#endif	/* IMAGEMANAGER_H */

