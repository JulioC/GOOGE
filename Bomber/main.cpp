#include <cstdlib>

#include "Bomber.h"

using namespace std;

int main(int argc, char** argv) {
    Game* game = new Bomber();
    
    if(!game->setup()) {
        return 1;
    }
    
    while(!game->ended()) {
        game->run();
    }
    
    game->cleanup();

    return 0;
}

