#include <cstdlib>
#include "Game.h"
#include "Sample.h"

using namespace std;

int main(int argc, char** argv) {
    Game* game = new Sample();
    
    if(!game->setup()) {
        return 1;
    }
    
    while(!game->ended()) {
        game->run();
    }
    
    game->cleanup();

    return 0;
}

