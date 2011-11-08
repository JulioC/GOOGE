#ifndef FIRSTSCENE_H
#define FIRSTSCENE_H

#include "Scene.h"

class FirstScene : public Scene {
public:
    FirstScene(Game* game);
    virtual ~FirstScene();

private:
    FirstScene(const FirstScene&);
    const FirstScene& operator=(const FirstScene&);

};

#endif  /* FIRSTSCENE_H */

