#ifndef GAME_H
#define	GAME_H

#include "Object.h"
#include "VideoManager.h"
#include "InputManager.h"

class Game: public Object {
public:
    static Game* instance();
    
    virtual ~Game();
    
    bool setup();
    void cleanup();
    
    void run();
    
    bool running() const;
    
private:
    Game();
    Game(const Game& orig);
    const Game& operator=(const Game& orig);
    
    static Game* _instance;
    
    bool _quit;
    
    VideoManager* _video;
    InputManager* _input;
    
};

#endif	/* GAME_H */

