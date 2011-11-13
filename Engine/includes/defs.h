#ifndef DEFS_H
#define	DEFS_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "Log.h"
#include "Vector.h"

typedef SDL_Color Color;

class Exception {
public:
    Exception(const char* message) {
        _message = new char[sizeof(message)];
        strcpy(_message, message);
    }
    virtual ~Exception() {
        delete[] _message;
    }
    
    const char* message() {
        return _message;
    }
    
private:
    char* _message;
};

class InitException : public Exception {
public:
    InitException(const char* message):
    Exception(message) {        
    }
};

class LoadException : public Exception {
public:
    LoadException(const char* message):
    Exception(message) {        
    }
};

#endif	/* DEFS_H */

