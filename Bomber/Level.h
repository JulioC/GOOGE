#ifndef LEVEL_H
#define	LEVEL_H

#include "Scene.h"

class Level: public Scene {
public:
    Level(Game* game);
    virtual ~Level();

private:
    Level(const Level&);
    const Level& operator=(const Level&);

};

#endif	/* LEVEL_H */

