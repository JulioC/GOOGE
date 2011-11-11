#ifndef TIMEHANDLER_H
#define	TIMEHANDLER_H

#include "defs.h"

class TimeHandler: public Object {
public:
    TimeHandler();
    ~TimeHandler();
        
    void update();
    
    int fps() const;
    int elapsed() const;

private:
    TimeHandler(const TimeHandler&);
    const TimeHandler& operator=(const TimeHandler&);
    
    int _lastTick;
    int _elapsed;
    int _frameCount;
    int _fps;

};

#endif	/* TIMEHANDLER_H */

