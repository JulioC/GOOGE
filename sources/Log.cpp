#include "Log.h"

#include <iostream>
#include <fstream>
#include <string>

const char* Log::_filename = "./log";
char Log::_last[256] = {0};

void Log::message(const char* msg, unsigned int caller, bool show) {
    sprintf(_last, "%s (0x%X)", msg, caller);
    
    if(show) {
        std::cout << _last << std::endl;
    }
    
    write(_last);
}

void Log::error(const char* msg, unsigned int caller, bool show) {
    sprintf(_last, "[ERROR] %s (0x%X)", msg, caller);
    
    if(show) {
        std::cout << _last << std::endl;
    }
    
    write(_last);
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
