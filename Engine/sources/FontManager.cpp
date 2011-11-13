#include "FontManager.h"
#include <sstream>

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
    char* str_size = strtok(NULL, ":");
    
    int size = 12;
    if(str_size != NULL) {
        size = atoi(str_size);
    }
    
    Font* font = NULL;
    try{
        font = new Font(_screen, filename, size);
    }
    catch(load_error e) {
        Log::error("Error on font load", this);
    }
    
    delete[] buffer;
        
    return font;
}

char* FontManager::identify(Font* obj) {
    const char* filename = obj->filename();
    char* identifier = new char[strlen(filename) + 16]; // extra space for size
    sprintf(identifier, "%s:%d", filename, obj->size());
    
    return identifier;
}
