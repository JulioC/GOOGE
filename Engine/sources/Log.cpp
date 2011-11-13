#include "Log.h"

#include <iostream>
#include <fstream>
#include <string>

char Log::_filename[256] = "./log";
char Log::_last[256] = {0};

Log::level Log::_level = Log::level_medium;

void Log::message(const Object* caller, const char* format, ...) {
    char description[256];
    va_list args;
    va_start(args, format);
    vsprintf(description, format, args);
    va_end(args);
    
    log(description, false, caller);
}

void Log::error(const Object* caller, const char* format, ...) {
    char description[256];
    va_list args;
    va_start(args, format);
    vsprintf(description, format, args);
    va_end(args);
    
    log(description, true, caller);
} 

void Log::setFile(const char* filename) {
    strcpy(_filename, filename);
}

void Log::setLevel(level lvl) {
    _level = lvl;
}

void Log::log(const char* description, bool error, const Object* caller) {
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    
    sprintf(_last,
            "[%02d:%02d:%02d] %s%s (OID#%08X)",
            timeinfo->tm_hour,
            timeinfo->tm_min,
            timeinfo->tm_sec,
            (error ? "ERROR: " : ""),
            description,
            (caller == NULL ? -1 : caller->id()));    
    
    if(_level == level_high) {
        std::cout << _last << std::endl;
        write(_last);
    }
    else if(_level == level_medium) {
        if(error) {
            std::cout << _last << std::endl;
        }
        write(_last);
    }
    else if(_level == level_low) {
        if(error) {
            std::cout << _last << std::endl;
            write(_last);
        }
    }
}

void Log::write(const char* message) {
    std::ofstream file;
    file.open(_filename, std::ios_base::app);
    if(file) {
        file << message << std::endl;
        file.close();
    }
}

const char* Log::last() {
    return _last;
}
