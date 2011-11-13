#ifndef IMAGE_H
#define	IMAGE_H

#include "Surface.h"

class Image: public Surface {
public:
    Image(SDL_Surface* _screen, const char* filename);
    ~Image();

    const char* filename() const;
    
    int width() const;
    int height() const;
    Vector size() const;
    
private:
    Image(const Image&);
    const Image& operator=(const Image&);

    char* _filename;
};

#endif	/* IMAGE_H */
