#ifndef BOMBER_H
#define	BOMBER_H

#include "Game.h"

class Bomber: public Game {
public:
    Bomber();
    ~Bomber();
    
    bool setup();
//    void cleanup();
//    
//    void run();
    
private:
    Bomber(const Bomber&);
    const Bomber& operator=(const Bomber&);

};

#endif	/* BOMBER_H */

