#include "VideoManager.h"

#include <SDL/SDL_ttf.h>

#include "Log.h"        

VideoManager* VideoManager::_instance = NULL;

VideoManager* VideoManager::instance() {
    if(_instance == NULL) {
        _instance = new VideoManager();
    }
    
    return _instance;
} 

VideoManager::VideoManager():
_screen(NULL),
_SDLInitiated(false),
_TTFInitiated(false) {
}

VideoManager::~VideoManager() {
    release();
}

bool VideoManager::init(const int width, const int height, const char* title) {
    SDL_InitSubSystem(SDL_INIT_VIDEO);
    
    if(!_SDLInitiated) {
        _screen = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

        if(_screen == NULL) {
            Log::error("Unable to get the video device", this);
            return false;
        }
        
        _SDLInitiated = true;
    }
    
    if(!_TTFInitiated) {
        if(TTF_Init() == -1) {
            Log::error("Unable to load font manager", this);
            return false;
        }
        
        _TTFInitiated = true;
    }
    
    SDL_WM_SetCaption(title, NULL);
    
    Log::message("VideoManager initiated", this);
    
    return true;
}

void VideoManager::release() {
    if(_TTFInitiated) {
        TTF_Quit();
        _TTFInitiated = false;
    }
    
    if(_SDLInitiated) {
        SDL_Quit();
        _SDLInitiated = false;
    }

    Log::message("VideoManager released", this);
    
    _screen = NULL;
}

bool VideoManager::initiated() const {
    return _SDLInitiated && _TTFInitiated;
}