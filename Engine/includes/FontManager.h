#ifndef FONTMANAGER_H
#define	FONTMANAGER_H

#include "defs.h"
#include "Font.h"
#include "ResourceManager.h"

class FontManager: public ResourceManager<Font> {
public:
    FontManager(SDL_Surface* screen);
    virtual ~FontManager();
    

private:
    FontManager(const FontManager&);
    const FontManager& operator=(const FontManager&);
    
    Font* load(const char* identifier);
    char* identify(Font* obj);
    
    SDL_Surface* _screen;

};

#endif	/* FONTMANAGER_H */

