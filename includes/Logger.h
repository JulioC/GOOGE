#ifndef LOGGER_H
#define	LOGGER_H

class Logger {
public:
    static void log(const char* message, unsigned int caller=-1, bool show=false);
    static void error(const char* message, unsigned int caller=-1, bool show=true);

    static const char* last();
    
    static void setFile(const char* filename);

private:
    Logger();
    Logger(const Logger&);
    const Logger& operator=(const Logger&);
    ~Logger();
    
    static void write(const char* message);
    
    static const char* _filename;
    static char _last[256];
    
};

#endif	/* LOGGER_H */
