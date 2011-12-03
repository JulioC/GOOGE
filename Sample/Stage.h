#ifndef STAGE_H
#define STAGE_H

#include "Layer.h"

class Stage: public Layer {
public:
    Stage(Game* game);
    virtual ~Stage();

private:
    Stage(const Stage&);
    const Stage& operator=(const Stage&);

};

#endif  /* STAGE_H */

