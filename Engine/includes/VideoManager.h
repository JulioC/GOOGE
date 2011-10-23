#ifndef VIDEOMANAGER_H
#define	VIDEOMANAGER_H

#include "Object.h"
#include "SDL/SDL.h"

class VideoManager: public Object {
public:
    static VideoManager* instance();
    
    ~VideoManager();
    
    bool init(const int width, const int height, const char* title);
    void release();

    void update();

    bool initiated() const;
    
private:
    VideoManager();
    VideoManager(const VideoManager&);
    const VideoManager& operator=(const VideoManager&);

    static VideoManager* _instance;
    
    bool _SDLInitiated;
    bool _TTFInitiated;
    
    SDL_Surface* _screen;
    
};

#endif	/* VIDEOMANAGER_H */

