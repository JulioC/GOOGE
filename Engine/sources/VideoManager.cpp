#include "VideoManager.h"

#include "ImageManager.h"        

VideoManager* VideoManager::_instance = NULL;

VideoManager* VideoManager::instance() {
    if(_instance == NULL) {
        _instance = new VideoManager();
    }
    
    return _instance;
} 

VideoManager::VideoManager():
_SDLInitiated(false),
_TTFInitiated(false),
_screen(NULL),
_images(NULL),
_fonts(NULL) {
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

        _images = new ImageManager(_screen);

        _SDLInitiated = true;
    }
    
    if(!_TTFInitiated) {
        if(TTF_Init() == -1) {
            Log::error("Unable to load font manager", this);
            Log::error(SDL_GetError(), this);
            return false;
        }
        
        _fonts = new FontManager(_screen);
        
        _TTFInitiated = true;
    }
    
    SDL_WM_SetCaption(title, NULL);
    
    Log::message("VideoManager initiated", this);
    
    return true;
}

void VideoManager::release() {
    if(_TTFInitiated) {
        if(_fonts != NULL) {
            delete _fonts;
            _fonts = NULL;
        }
        
        TTF_Quit();
        _TTFInitiated = false;
    }
    
    if(_SDLInitiated) {
        if(_images != NULL) {
            delete _images;
            _images = NULL;
        }
        
        _SDLInitiated = false;
    }
    
    SDL_QuitSubSystem(SDL_INIT_VIDEO);

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

ImageManager* VideoManager::images() const {
    return _images;
}

FontManager* VideoManager::fonts() const {
    return _fonts;
}