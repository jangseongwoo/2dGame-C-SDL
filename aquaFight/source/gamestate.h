
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "gameengine.h"

class GameState
{
public:
    GameState() { }
    virtual void init(void) = 0;
    virtual void cleanup(void) = 0;

    virtual void pause(void) = 0;
    virtual void resume(void) = 0;

    virtual void handleEvents(void) = 0;
    virtual void update(void) = 0;
    virtual void draw(void) = 0;

};

#endif
