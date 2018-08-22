
#ifndef INTROSTATE_H
#define INTROSTATE_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "gamestate.h"
#include "sprite.h"

class PlayState : public GameState
{
    SDL_Texture *bgTexture;
    Sprite *player;
    float chDegree;
	int timeCount;
	int enemyNumber;
	int selectEnemy;
	int selectEnemyfly;
	int enemyNumberfly;


    TTF_Font *font;
    SDL_Texture *msg1, *msg2;

    Mix_Music *bgm;
    bool bgmPlaying;

    int no;
    Mix_Chunk *walk1, *walk2, *walk3, *walk4 , *walk5;
    

public:


	PlayState() { }

	void init(void);
	void cleanup(void);

	void pause(void);
	void resume(void);

	void handleEvents(void);
	void update(void);
	void draw(void);
};

#endif
