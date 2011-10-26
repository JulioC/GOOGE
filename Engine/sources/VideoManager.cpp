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

bool VideoManager::init(int width, int height, const char* title) {
    SDL_InitSubSystem(SDL_INIT_VIDEO);
    
    if(!_SDLInitiated) {
        _screen = SDL_SetVideoMode(width, height, 0, SDL_HWSURFACE|SDL_DOUBLEBUF);

        if(_screen == NULL) {
            Log::error("Unable to get the video device", this);
            Log::error(SDL_GetError(), this);
            return false;
        }
        
        _SDLInitiated = true;
    }
    
    if(!_TTFInitiated) {
        if(TTF_Init() == -1) {
            Log::error("Unable to load font manager", this);
            Log::error(SDL_GetError(), this);
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

void VideoManager::update() {
    if(!SDL_Flip(_screen) == -1) {
        Log::error("Failed to vsync", this);
        Log::error(SDL_GetError(), this);
    }
}

bool VideoManager::initiated() const {
    return _SDLInitiated && _TTFInitiated;
}

Image* VideoManager::getImage(const char* filename) {
    if(_images[filename] == NULL) {
        Image* img = new Image();
        if(!img->load(filename)) {
            delete img;
            return NULL;
        }
        img->screen(_screen);
        
        ImageResource* res = new ImageResource();
        res->image = img;
        res->refCount = 0;
        
        _images[filename] = res;
    }
    
    _images[filename]->refCount++;
    
    return _images[filename]->image;
}

void VideoManager::releaseImage(Image** image) {
    const char* filename = (*image)->filename();
    
    _images[filename]->refCount--;
    if(_images[filename]->refCount == 0) {
        delete _images[filename]->image;
        delete _images[filename];
        _images.erase(filename);
    }
    
    *image = NULL;
}
