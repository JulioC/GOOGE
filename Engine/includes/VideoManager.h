#ifndef VIDEOMANAGER_H
#define	VIDEOMANAGER_H

#include <map>
#include <string>

#include "defs.h"
#include "FontManager.h"
#include "ImageManager.h"
#include "Object.h"

class VideoManager: public Object {
public:
    static VideoManager* instance();
    
    ~VideoManager();
    
    void init(int width, int height, const char* title);
    void release();

    void update();

    bool initiated() const;
    
    ImageManager* images() const;
    FontManager* fonts() const;
    
private:    
    VideoManager();
    VideoManager(const VideoManager&);
    const VideoManager& operator=(const VideoManager&);

    static VideoManager* _instance;
    
    bool _SDLInitiated;
    bool _TTFInitiated;
    
    SDL_Surface* _screen;
    
    ImageManager* _images;
    FontManager* _fonts;
};

#endif	/* VIDEOMANAGER_H */

