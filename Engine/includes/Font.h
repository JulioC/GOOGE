#ifndef FONT_H
#define	FONT_H

#include "defs.h"

class Font: public Object {
public:
    Font(const char* filename, int size);
    virtual ~Font();
    
    const char* filename() const;
    int size() const;
  
    //@TODO: implement Font::render
//    Text* render(const char* str, SDL_Surface screen);
    
private:
    Font(const Font&);
    const Font& operator=(const Font&);

    int _size;
    char* _filename;

    TTF_Font* _font;
    
};

#endif	/* FONT_H */

