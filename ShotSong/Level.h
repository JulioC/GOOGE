#ifndef LEVEL_H
#define	LEVEL_H

#include "Scene.h"

class Game;

class Level : public Scene {
public:
    Level(Game* parent);
    virtual ~Level();
    
    virtual bool init();
    
private:

    Level(const Level& orig);
    

};

#endif	/* LEVEL_H */

