#include <cstdlib>
#include "Game.h"
#include "Sample.h"

using namespace std;

int main(int argc, char** argv) {
    Game* game = new Sample();
    
    try {
        game->setup();
        
        while(!game->ended()) {
            game->run();
        }
    }
    catch(Exception e) {
        game->cleanup();
    }

    game->cleanup();
    
    return 0;
}

