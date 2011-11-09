#ifndef LOG_H
#define	LOG_H

#include "defs.h"
#include "Object.h"

class Log {
public:
    static void message(const char* msg, const Object* caller, bool show=false);
    static void error(const char* msg, const Object* caller, bool show=true);

    static const char* last();
    
    static void setFile(const char* filename);

private:
    Log();
    Log(const Log&);
    const Log& operator=(const Log&);
    ~Log();
    
    static void write(const char* message);
    
    static const char* _filename;
    static char _last[256];
    
};

#endif	/* LOG_H */
