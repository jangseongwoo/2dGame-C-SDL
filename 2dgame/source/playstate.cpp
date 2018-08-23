#include <SDL.h>
#include "gameengine.h"
#include "gamestate.h"
#include "playstate.h"
#include "sprite.h"
#include "enemy.h"
#include "enemyfly.h"
#include "flyunit.h"
#include "arrow.h"
#include "ending.h"
#include "win.h"

PlayState playState;
extern Ending ending;
extern GameEngine game;
extern Win win;

float mana=0;
int i=0;
int fly=0;
int Anumber=0;
Sprite* characterNumber[100];
Enemy* enemy[100];
Flyunit* characterNumber1[100];
EnemyFly* enemyfly[100];
Arrow* arrow[100];
int time=0;
int castle=1000;
int enemyCastle=1000;



void PlayState::init(void)
{
	timeCount=0;
	enemyNumber=0;
	enemyNumberfly=0;
	SDL_GetTicks();
	// Load background image
	SDL_Surface *bmp2 = SDL_LoadBMP("background.bmp");
	bgTexture = SDL_CreateTextureFromSurface(game.renderer, bmp2);
	SDL_FreeSurface(bmp2);

	font = TTF_OpenFont("NanumBarunGothic.ttf", 30);
	SDL_Color color={0,0,0};

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	bgm = Mix_LoadMUS("BGM/Idecide.mp3");
	bgmPlaying = true;
	Mix_PlayMusic(bgm, -1);

	walk1 = Mix_LoadWAV("BGM/sound.wav");
	walk2 = Mix_LoadWAV("BGM/sound2.wav");
	walk3 = Mix_LoadWAV("BGM/sound3.wav");
	walk4 = Mix_LoadWAV("BGM/sound4.wav");
	walk5 = Mix_LoadWAV("BGM/sound5.wav");
}

void PlayState::cleanup(void)
{
	Mix_FreeChunk(walk1);
	Mix_FreeChunk(walk2);
	Mix_FreeChunk(walk3);
	Mix_FreeChunk(walk4);
	Mix_FreeChunk(walk5);

	Mix_HaltMusic();
	Mix_FreeMusic(bgm);
	Mix_CloseAudio();
	TTF_CloseFont(font);
	SDL_DestroyTexture(bgTexture);
	SDL_DestroyTexture(msg1);
	SDL_DestroyTexture(msg2);
}

void PlayState::pause(void)
{
}

void PlayState::resume(void)
{
}

void PlayState::handleEvents(void)
{
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			game.quit();
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_ESCAPE:
				game.quit();
				break;
			case SDLK_LEFT:

				break;
			case SDLK_RIGHT:

				break;
			case SDLK_p:
				Mix_PauseMusic();
				bgmPlaying = false;
				break;
			case SDLK_r:
				Mix_ResumeMusic();
				bgmPlaying = true;
				break;
			case SDLK_1:
				if(mana>5){
				characterNumber[i]=new Sprite;
				characterNumber[i]->createCharacter(1);
				characterNumber[i]->hp=25;
				mana-=5;
				i++;
				}
				break;
			case SDLK_2:
				if(mana>7){
				characterNumber[i]=new Sprite;
				characterNumber[i]->createCharacter(2);
				characterNumber[i]->hp=25;
				mana-=7;
				i++;		
				}
				break;
			case SDLK_3:
				if(mana>10){
				characterNumber[i]=new Sprite;
				characterNumber[i]->createCharacter(3);
				characterNumber[i]->hp=25;
				i++;		
				mana-=10;
				}

				break;
			case SDLK_4:
				if(mana>15){
				characterNumber[i]=new Sprite;
				characterNumber[i]->createCharacter(4);
				characterNumber[i]->hp=25;
				i++;
				mana-=15;
				}
				break;

			case SDLK_5:
				if(mana>3){
				characterNumber1[fly]=new Flyunit;
				characterNumber1[fly]->createCharacter(1);
				characterNumber1[fly]->hp=25;
				fly++;
				mana-=3;
				}
				break;

			case SDLK_6:
				if(mana>5){
				characterNumber1[fly]=new Flyunit;
				characterNumber1[fly]->createCharacter(2);
				characterNumber1[fly]->hp=25;
				fly++;
				mana-=5;
				}
				break;
			case SDLK_7:
				if(mana>7){
				characterNumber1[fly]=new Flyunit;
				characterNumber1[fly]->createCharacter(3);
				characterNumber1[fly]->hp=25;
				fly++;
				mana-=7;
				}
				break;
			case SDLK_8:
				if(mana>10){
				characterNumber1[fly]=new Flyunit;
				characterNumber1[fly]->createCharacter(4);
				characterNumber1[fly]->hp=25;
				fly++;
				mana-=10;
				}
				break;

			case SDLK_9:

				/*
				enemyfly[enemyNumberfly]=new EnemyFly;
		enemyfly[enemyNumberfly]->createCharacter(4);
		enemyfly[enemyNumberfly]->hp=25;
		enemyNumberfly++;
		break;
		*/  break;

			case SDLK_SPACE:
				arrow[Anumber]=new Arrow;
				Anumber++;
					if(!Mix_Playing(5)){
						Mix_PlayChannel(5, walk5, 0); no = 5;
					}
				break;




			}
			break;

		case SDL_KEYUP:
			switch (event.key.keysym.sym) {
			case SDLK_LEFT:
			case SDLK_RIGHT:

				break;
			}
			break;
		}
	}




}

void PlayState::update(void)
{
	selectEnemy=rand()%3+1;
	if((timeCount%350)==0){
		enemy[enemyNumber]=new Enemy;
		enemy[enemyNumber]->createCharacter(selectEnemy);
		enemy[enemyNumber]->hp=25;
		enemyNumber++;
	}
	timeCount++;

	selectEnemyfly=rand()%3+1;
	if((timeCount%500)==0){
		enemyfly[enemyNumberfly]=new EnemyFly;
		enemyfly[enemyNumberfly]->createCharacter(selectEnemyfly);
		enemyfly[enemyNumberfly]->hp=25;
		enemyNumberfly++;
	}

	if(enemyCastle<=100){
	selectEnemyfly=rand()%3+1;
	if((timeCount%250)==0){
		enemyfly[enemyNumberfly]=new EnemyFly;
		enemyfly[enemyNumberfly]->createCharacter(selectEnemyfly);
		enemyfly[enemyNumberfly]->hp=25;
		enemyNumberfly++;
	}
	}
	if((time/1000)>=1200)
		game.changeState(&ending);



	for(int j=0;j<i;j++){
		characterNumber[j]->update();}

	for(int b=0;b<enemyNumber;b++)
		enemy[b]->update();

	for(int i=0;i<fly;i++)
		characterNumber1[i]->update();

	for(int k=0;k<enemyNumberfly;k++)
		enemyfly[k]->update();

	for(int a=0;a<Anumber;a++)
		arrow[a]->update();

	for(int a=0;a<i;a++){
		for(int b=0;b<enemyNumber;b++){
			if(characterNumber[a]->hp >=0){
				if(enemy[b]->hp >= 0){
					if((enemy[b]->px - characterNumber[a]->px)<=40){
						characterNumber[a]->attack();
						enemy[b]->attack();
						characterNumber[a]->hp--;
						enemy[b]->hp--;
						if(!Mix_Playing(1))
						Mix_PlayChannel(1, walk1, 0); no = 1;
						
					}
					//	else{
					//	characterNumber[a]->walk();
					//enemy[b]->walk();
					//	}			
				}

			}
			if(enemy[b]->hp!=0 && characterNumber[a]->hp<=0)
				enemy[b]->walk();
		}

	}

	
	for(int a=0;a<fly;a++){
		for(int b=0;b<enemyNumberfly;b++){
			if(characterNumber1[a]->hp >=0){
				if(enemyfly[b]->hp >= 0){
					if((enemyfly[b]->px - characterNumber1[a]->px)<=40){
						characterNumber1[a]->attack();
						enemyfly[b]->attack();
						characterNumber1[a]->hp--;
						enemyfly[b]->hp--;
						if(!Mix_Playing(4))
						Mix_PlayChannel(4, walk4, 0); no = 4;
					}
					//	else{
					//	characterNumber[a]->walk();
					//enemy[b]->walk();
					//	}			
				}

			}
			if(enemyfly[b]->hp!=0 && characterNumber1[a]->hp<=0)
				enemyfly[b]->walk();
		}

	}


	for(int e=0;e<enemyNumber;e++){
		if(enemy[e]->px<=220){
			enemy[e]->attack();
			castle-=1;
		}
	}
	for(int e=0;e<enemyNumberfly;e++){
		if(enemyfly[e]->px<=220){
			enemyfly[e]->attack();
			castle-=1;
			walk3 = Mix_LoadWAV("Effect/walk2-1.wav"); 
		}
	}
	for(int e=0;e<i;e++){
		if(characterNumber[e]->px>=880){
			characterNumber[e]->attack();
			enemyCastle-=10;
			walk2 = Mix_LoadWAV("Effect/walk1-2.wav"); 
		}
	}
	for(int e=0;e<fly;e++){
		if(characterNumber1[e]->px>=880){
			characterNumber1[e]->attack();
			enemyCastle-=10;

		}
	}

	if(enemyCastle==0)
		game.changeState(&win);
	if(castle==0)
		game.changeState(&ending);

	time=SDL_GetTicks();
	mana+=0.05;

	/*
	for(int e=0;e<enemyNumber;e++){
		if(enemy[e]->hp==0){
			enemy[e]=NULL;
			
		}
	}
	for(int e=0;e<enemyNumberfly;e++){
		if(enemyfly[e]->hp==0){
			enemyfly[e]=NULL;
			castle-=10;
		}
	}
	for(int e=0;e<i;e++){
		if(characterNumber[e]->hp==0){
			characterNumber[e]=NULL;
			
		}
	}
	for(int e=0;e<Anumber;e++){
		if(characterNumber1[e]->hp==0){
			characterNumber1[e]=NULL;
		}
	}
	*/


}

void PlayState::draw(void)
{
	SDL_RenderClear(game.renderer);
	SDL_RenderCopy(game.renderer, bgTexture, NULL, NULL);

	for(int j=0;j<i;j++){
		if(characterNumber[j]->hp>=0){
			characterNumber[j]->draw();}
	}
	for(int a=0;a<enemyNumber;a++){
		if(enemy[a]->hp>=0){
			enemy[a]->draw();}
	}
	for(int i=0;i<fly;i++){
		if(characterNumber1[i]->hp>=0){
			characterNumber1[i]->draw();}
	}

	for(int k=0;k<enemyNumberfly;k++){
		if(enemyfly[k]->hp>=0)
			enemyfly[k]->draw();
	}

	for(int a=0;a<Anumber;a++)
		if(arrow[a]->py<=250)
			arrow[a]->draw();
			


	char str[100];
	SDL_Rect rect2 = {420, 0, 0, 0};
    sprintf(str, "Time: %d second", time/1000);
    SDL_Color color={0,0,255};
    SDL_Surface *img1 = TTF_RenderText_Blended(font, str, color);
    SDL_Texture *emsg1 = SDL_CreateTextureFromSurface(game.renderer, img1);
    SDL_QueryTexture(emsg1, NULL, NULL, &rect2.w, &rect2.h);
    SDL_RenderCopy(game.renderer, emsg1, NULL, &rect2);
    SDL_FreeSurface(img1);
    SDL_DestroyTexture(emsg1);

	char str1[100];
	SDL_Rect rect3 = {50, 0, 0, 0};
    sprintf(str1, "Mana: %lf ", mana);
   // SDL_Color color={0,255,255};
    SDL_Surface *img = TTF_RenderText_Blended(font, str1, color);
    SDL_Texture *emsg = SDL_CreateTextureFromSurface(game.renderer, img);
    SDL_QueryTexture(emsg, NULL, NULL, &rect3.w, &rect3.h);
    SDL_RenderCopy(game.renderer, emsg, NULL, &rect3);
    SDL_FreeSurface(img);
    SDL_DestroyTexture(emsg);
	

	SDL_RenderPresent(game.renderer);
}
