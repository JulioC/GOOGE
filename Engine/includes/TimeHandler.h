#ifndef TIMEHANDLER_H
#define	TIMEHANDLER_H

class TimeHandler {
public:
    TimeHandler();
    ~TimeHandler();
        
    bool init();
    void release();
    
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

