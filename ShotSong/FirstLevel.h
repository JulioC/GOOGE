#ifndef FIRSTLEVEL_H
#define FIRSTLEVEL_H

#include "Level.h"

class FirstLevel: public Level {
public:
    FirstLevel(Game* game);
    virtual ~FirstLevel();

private:
    FirstLevel(const FirstLevel&);
    const FirstLevel& operator=(const FirstLevel&);

};

#endif  /* FIRSTLEVEL_H */

