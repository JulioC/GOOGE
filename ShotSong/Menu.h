#ifndef MENU_H
#define	MENU_H
#include "Scene.h"

class Game;
class InputManager;
class VideoManager;

class Menu : public Scene {
public:
    Menu(Game* parent, VideoManager* video, InputManager* input);
    void update();
    void draw();
    
private:

    Menu(const Menu& orig);
    virtual ~Menu();
    
    bool _temp;

};

#endif	/* MENU_H */

