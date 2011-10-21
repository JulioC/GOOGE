#include "Game.h"

using namespace std;

int main(int argc, char** argv) {
    Game* game = Game::instance();
    
    if(!game->setup()) {
        return 1;
    }
    
    while(!game->ended()) {
        game->run();
    }
    
    game->cleanup();  
    
    return 0;
}

