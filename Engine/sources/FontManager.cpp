#include "FontManager.h"
#include <sstream>

FontManager::FontManager(SDL_Surface* screen):
ResourceManager(),
_screen(screen) {
}

FontManager::~FontManager() {
}

Font* FontManager::load(const char* identifier) {
    char* buffer = new char[sizeof(identifier)];
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
    catch(LoadException e) {
        Log::error(this, "Unable to loaf font \"%s\"", filename);
    }
    
    delete[] buffer;
        
    return font;
}

char* FontManager::identify(Font* obj) {
    const char* filename = obj->filename();
    char* identifier = new char[sizeof(filename) + 16]; // extra space for size
    sprintf(identifier, "%s:%d", filename, obj->size());
    
    return identifier;
}
