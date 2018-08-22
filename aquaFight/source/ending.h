
#ifndef ENDING_H
#define ENDING_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "gamestate.h"
#include "sprite.h"

class Ending : public GameState
{
    SDL_Texture *bgTexture;
    
    

    TTF_Font *font;
    SDL_Texture *msg1, *msg2;

    Mix_Music *bgm;
    bool bgmPlaying;

    int no;
    
    

public:
	Ending() { }

	void init(void);
	void cleanup(void);

	void pause(void);
	void resume(void);

	void handleEvents(void);
	void update(void);
	void draw(void);
};

#endif
