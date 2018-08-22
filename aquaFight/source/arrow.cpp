#include <SDL.h>
#include "gameengine.h"
#include "gamestate.h"
#include "playstate.h"
#include "arrow.h"

extern GameEngine game;

Arrow::Arrow(void)
{
	// Load character sprite image
	SDL_Surface *bmp1 = SDL_LoadBMP("arrow.bmp");
	Uint32 colorkey = SDL_MapRGB(bmp1->format, 255, 255,255);
	SDL_SetColorKey(bmp1, SDL_TRUE, colorkey);
	sheetTexture = SDL_CreateTextureFromSurface(game.renderer, bmp1);
	SDL_FreeSurface(bmp1);

	action = WALK;

	frame = 0;

	px = 230;
	py = 60;
}

Arrow::~Arrow()
{
	SDL_DestroyTexture(sheetTexture);
}

void Arrow::walk(void)
{
	if (action != WALK) {
		action = WALK;
		frame = 0;
	}
}

void Arrow::attack(void)
{
	if (action != ATTACK) {
		action = ATTACK;
		frame = 0;
	}
}

float x=4;
float y=1.0;
void Arrow::update(void)
{
	//static int count = 0;

	/*
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
	*/

	px+=x;
	py+=y+1;


	if(px<250)
		x=2;
	else
		x=0.9;

	
}


void Arrow::draw(void)
{
	SDL_Rect sheetRect, playerRect;
	sheetRect.x = frame * 10;
	sheetRect.y =  10;
	sheetRect.w = 50;
	sheetRect.h = 50;
	playerRect.x = px;
	playerRect.y = py;
	playerRect.w = 20;
	playerRect.h = 20;

	SDL_RenderCopy(game.renderer, sheetTexture, &sheetRect, &playerRect);
}

void Arrow::createCharacter(int i){
	if(i==1)
		character=0;
	if(i==2)
		character=1;
	if(i==3)
		character=2;
	if(i==4)
		character=3;

}

