#ifndef LEVELTEST_H
#define	LEVELTEST_H

#include "Level.h"

class Game;

class LevelTest : public Level {
public:
    LevelTest(Game* parent);
    bool init();
    
private:

    LevelTest(const LevelTest& orig);
    virtual ~LevelTest();

};

#endif	/* LEVELTEST_H */

