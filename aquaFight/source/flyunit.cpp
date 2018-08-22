#include <SDL.h>
#include "gameengine.h"
#include "gamestate.h"
#include "playstate.h"
#include "flyunit.h"

extern GameEngine game;

Flyunit::Flyunit(void)
{
	// Load character sprite image
	SDL_Surface *bmp1 = SDL_LoadBMP("flyunit.bmp");
	Uint32 colorkey = SDL_MapRGB(bmp1->format, 255, 0, 0);
	SDL_SetColorKey(bmp1, SDL_TRUE, colorkey);
	sheetTexture = SDL_CreateTextureFromSurface(game.renderer, bmp1);
	SDL_FreeSurface(bmp1);

	action = WALK;

	frame = 0;

	px = 200;
	py = 100;
}

Flyunit::~Flyunit()
{
	SDL_DestroyTexture(sheetTexture);
}

void Flyunit::walk(void)
{
	if (action != WALK) {
		action = WALK;
		frame = 0;
	}
}

void Flyunit::attack(void)
{
	if (action != ATTACK) {
		action = ATTACK;
		frame = 0;
	}
}


void Flyunit::update(void)
{
	static int count = 0;


	if(action==WALK){
		if (count % 5 == 0)
			frame = (frame + 1) % 3;
		count = (count + 1) % 5;

		px += 1;
	}
	if(action==ATTACK){
		if (count % 5 == 0)
			frame = ((frame + 1) % 3)+3;
		count = (count + 1) % 5;
		//px = 1;
	}
}


void Flyunit::draw(void)
{
	SDL_Rect sheetRect, playerRect;
	sheetRect.x = frame * 150;
	sheetRect.y = character * 100;
	sheetRect.w = 100;
	sheetRect.h = 80;
	playerRect.x = px;
	playerRect.y = py;
	playerRect.w = 100;
	playerRect.h = 100;

	SDL_RenderCopy(game.renderer, sheetTexture, &sheetRect, &playerRect);
}

void Flyunit::createCharacter(int i){
	if(i==1)
		character=0;
	if(i==2)
		character=1;
	if(i==3)
		character=2;
	if(i==4)
		character=3;

}

