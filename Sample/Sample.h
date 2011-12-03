#ifndef SAMPLE_H
#define SAMPLE_H

#include "Game.h"

class Sample: public Game {
public:
    Sample();
    ~Sample();
    
    void setup();

private:
    Sample(const Sample&);
    const Sample& operator=(const Sample&);

};

#endif  /* SAMPLE_H */

