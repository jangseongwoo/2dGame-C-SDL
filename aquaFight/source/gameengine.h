
#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "debug.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include <vector>
using namespace std;

class GameState;

class GameEngine
{
public:

    void init(const char* title, int width=480, int height=272, bool fullscreen=false);
    void cleanup(void);

    void changeState(GameState* state);
    void pushState(GameState* state);
    void popState(void);

    void handleEvents(void);
    void update(void);
    void draw(void);

    bool running() { return m_running; }
    void quit() { m_running = false; }

    SDL_Window *window;
    SDL_Renderer *renderer;

private:
    // the stack of states
    vector<GameState*> states;

    bool m_running;
    bool m_fullscreen;
};

#endif
