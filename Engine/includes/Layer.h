#ifndef LAYER_H
#define	LAYER_H

#include <vector>

#include "Object.h"
#include "Sprite.h"

class Layer : public Object {
public:
    Layer();
    virtual ~Layer();
    
    virtual void update();
    virtual void draw();
    
    //@TODO: Find a better way to manage the layer sprites
    void addSprite(Sprite* sprite);
    void removeSprite(int index);
    int nextIndex() const;
    
private:
    Layer(const Layer&);
    
    std::vector<Sprite*> _sprites;

};

#endif	/* LAYER_H */

