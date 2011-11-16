#ifndef LOG_H
#define	LOG_H

#include "defs.h"
#include "Object.h"

class Log {
public:
    enum level {
        level_high, // show everything, write everything
        level_medium, // show errors, write everything
        level_low, // show nothing, write errors
        level_none // show nothing, write nothing
    };
    
    static void message(const Object* caller, const char* format, ...);
    static void error(const Object* caller, const char* format, ...);

    static const char* last();
    
    static void setFile(const char* filename);
    static void setLevel(level lvl);

private:
    Log();
    Log(const Log&);
    const Log& operator=(const Log&);
    ~Log();
    
    static void log(const Object* caller, const char* description, bool error=false);
    
    static void write(const char* message);
        
    static char _filename[256];
    static char _last[256];
    
    static level _level;
    
};

#endif	/* LOG_H */
