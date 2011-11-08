#ifndef INTRO_H
#define	INTRO_H

#include "Scene.h"

class Intro: public Scene {
public:
    Intro(Game* game);
    virtual ~Intro();
    
private:
    Intro(const Intro&);
    const Intro& operator=(const Intro&);

};

#endif	/* INTRO_H */

