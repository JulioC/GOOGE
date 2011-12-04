#include <cstdlib>
#include "Game.h"
#include "Sample.h"

int main(int argc, char** argv) {
    Log::setLevel(Log::level_high);
    Game* game = new Sample();
    
    try {
        game->setup();
        
        while(!game->ended()) {
            game->run();
        }
    }
    catch(Exception e) {
    }

    game->cleanup();
    
    return 0;
}

