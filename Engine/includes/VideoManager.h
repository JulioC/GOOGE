#ifndef VIDEOMANAGER_H
#define	VIDEOMANAGER_H

#include <map>
#include <string>

#include "Object.h"
#include "ImageManager.h"
#include "Image.h"
#include "SDL/SDL.h"

class VideoManager: public Object {
private:
    struct ImageResource {
        unsigned int refCount;
        Image* image;
    };
    
public:
    static VideoManager* instance();
    
    ~VideoManager();
    
    bool init(int width, int height, const char* title);
    void release();

    void update();

    bool initiated() const;
    
    SDL_Surface* screen() const;
    ImageManager* images() const;
    
private:    
    VideoManager();
    VideoManager(const VideoManager&);
    const VideoManager& operator=(const VideoManager&);

    static VideoManager* _instance;
    
    bool _SDLInitiated;
    bool _TTFInitiated;
    
    SDL_Surface* _screen;
    
    ImageManager* _images;
};

#endif	/* VIDEOMANAGER_H */

