#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "gameengine.h"
#include "gamestate.h"


GameEngine game;

void GameEngine::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = SDL_WINDOW_SHOWN;

    if (fullscreen)
        flags |= SDL_WINDOW_FULLSCREEN;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_ShowCursor(false);

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000 ,400, flags);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	m_fullscreen = fullscreen;
	m_running = true;

    TTF_Init();

}

void GameEngine::cleanup(void)
{
	while ( !states.empty() ) {
		states.back()->cleanup();
		states.pop_back();
	}

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_Quit();
	SDL_Quit();
}

void GameEngine::changeState(GameState* state)
{
	// cleanup the current state
	if ( !states.empty() ) {
		states.back()->cleanup();
		states.pop_back();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->init();
}

void GameEngine::pushState(GameState* state)
{
	// pause current state
	if ( !states.empty() ) {
		states.back()->pause();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->init();
}

void GameEngine::popState()
{
	// cleanup the current state
	if ( !states.empty() ) {
		states.back()->cleanup();
		states.pop_back();
	}

	// resume previous state
	if ( !states.empty() ) {
		states.back()->resume();
	}
}

void GameEngine::handleEvents()
{
	// let the state handle events
	states.back()->handleEvents();
}

void GameEngine::update()
{
	// let the state update the game
	states.back()->update();
}

void GameEngine::draw()
{
	// let the state draw the screen
	states.back()->draw();
}
