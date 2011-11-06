#ifndef MENU_H
#define	MENU_H
#include "Scene.h"

class Game;
class InputManager;
class VideoManager;

class Menu : public Scene {
public:
    Menu(Game* parent, VideoManager* video, InputManager* input);
    
private:

    Menu(const Menu& orig);
    virtual ~Menu();

};

#endif	/* MENU_H */

