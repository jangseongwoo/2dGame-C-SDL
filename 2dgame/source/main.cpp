#include "gameengine.h"
#include "playstate.h"
#include "Start.h"

extern PlayState playState;
extern Start start;

extern GameEngine game;

int main ( int argc, char *argv[] )
{
    game.init( "JSW-Project" );

    freopen("CON", "w", stdout);
    freopen("CON", "w", stderr);

    game.changeState(&start);

    while ( game.running() )
    {
        game.handleEvents();
        game.update();
        game.draw();  
    }

    game.cleanup();

    return 0;
}
