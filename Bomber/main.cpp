#include "Log.h"
#include "Bomber.h"

using namespace std;

int main(int argc, char** argv) {
    Log::setLevel(Log::level_high);
    Game* game = new Bomber();
    
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

