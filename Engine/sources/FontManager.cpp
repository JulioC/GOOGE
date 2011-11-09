#include "FontManager.h"

FontManager::FontManager(SDL_Surface* screen):
ResourceManager(),
_screen(screen) {
}

FontManager::~FontManager() {
}

Font* FontManager::load(const char* identifier) {
    int len = strlen(identifier);
    char* buffer = new char[len + 1];
    strcpy(buffer, identifier);
    
    char* filename = strtok(buffer, ":");
    char* str_size = strtok(buffer, ":");
    
    int size = 12;
    if(str_size != NULL) {
        size = atoi(str_size);
    }
    
    Font* font;
    try{
        font = new Font(filename, size);
    }
    catch(load_error e) {
        Log::error("Error on font load", this);
    }
        
    return font;
}

std::string FontManager::identify(Font* obj) {
    return std::string(obj->filename());
}
