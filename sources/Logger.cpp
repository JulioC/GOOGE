#include "Logger.h"

#include <iostream>
#include <fstream>
#include <string>

const char* Logger::_filename = "./log";
char Logger::_last[256] = {0};

void Logger::log(const char* message, unsigned int caller, bool show) {
    sprintf(_last, "%s (0x%X)", message, caller);
    
    if(show) {
        std::cout << _last << std::endl;
    }
    
    Logger::write(_last);
}

void Logger::error(const char* message, unsigned int caller, bool show) {
    sprintf(_last, "[ERROR] %s (0x%X)", message, caller);
    
    if(show) {
        std::cout << _last << std::endl;
    }
    
    Logger::write(_last);
} 

void Logger::write(const char* message) {
    std::ofstream file;
    file.open(_filename, std::ios_base::app);
    if(file) {
        file << message << std::endl;
        file.close();
    }
}

const char* Logger::last() {
    return _last;
}
