#include <cstdlib>
#include "Game.h"
#include "ShotSong.h"
using namespace std;

int main(int argc, char** argv) {
    ShotSong* game = new ShotSong();
    
    if(!game->setup()) {
        return 1;
    }
    
    while(!game->ended()) {
        game->run();
    }
    
    game->cleanup();

    return 0;
}