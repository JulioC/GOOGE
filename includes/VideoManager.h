#ifndef VIDEOMANAGER_H
#define	VIDEOMANAGER_H

#include "Object.h"
#include "SDL/SDL.h"

class VideoManager: public Object {
public:
    VideoManager();
    ~VideoManager();
    
    bool init(const int width, const int height, const char* title);
    void release();
    
private:
    VideoManager(const VideoManager&);
    const VideoManager& operator=(const VideoManager&);
    
    SDL_Surface* _screen;
    
};

#endif	/* VIDEOMANAGER_H */

