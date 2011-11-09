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
    
    Font* font = NULL;
    try{
        font = new Font(filename, size);
    }
    catch(load_error e) {
        Log::error("Error on font load", this);
    }
    
    delete[] buffer;
        
    return font;
}

std::string FontManager::identify(Font* obj) {
    std::string identifier = "";
    identifier += obj->filename();
    identifier += ":";
    identifier += obj->size();
    
    return identifier;
}
