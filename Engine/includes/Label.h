#ifndef LABEL_H
#define	LABEL_H

#include "defs.h"
#include "Entity.h"
#include "Font.h"
#include "Text.h"

class Game;

class Label: public Entity {
public:
    Label(Game* game, const char* fontname, int size=12);
    virtual ~Label();

    virtual void update();
    virtual void draw();
    
    void setPosition(const Vector& position);
    void setColor(const Color& color);

    const char* getMessage() const;
    void setMessage(const char* message);
    
protected:
    Vector _position;
    
private:
    Label(const Label&);
    const Label& operator=(const Label&);

    void render();
    
    const char* _message;

    Color _color;
    
    Font* _font;
    Text* _text;

};

#endif	/* LABEL_H */

