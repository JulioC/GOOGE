#include <SDL/SDL_ttf.h>

#include "VideoManager.h"
#include "Log.h"        

VideoManager::VideoManager() {
}

VideoManager::~VideoManager() {
}

bool VideoManager::init(const int width, const int height, const char* title) {
    _screen = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    
    if(_screen == NULL||TTF_Init() == -1) {
        Log::error("Unable to get the video device", this);
        return false;
    }
    else {
        SDL_WM_SetCaption(title, NULL);
        Log::message("Video device initialized", this);
        return true;
    }
    
}