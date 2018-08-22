#include <SDL.h>
#include "gameengine.h"
#include "gamestate.h"
#include "playstate.h"
#include "sprite.h"
#include "Start.h"

Start start;
extern GameEngine game;
extern PlayState playState;

void Start ::init(void)
{
    

    // Load background image
    SDL_Surface *bmp2 = SDL_LoadBMP("start.bmp");
    bgTexture = SDL_CreateTextureFromSurface(game.renderer, bmp2);
    SDL_FreeSurface(bmp2);

    font = TTF_OpenFont("NanumBarunGothic.ttf", 30);
    SDL_Color color={0,0,0};
    SDL_Surface *msgbmp1 = TTF_RenderText_Blended(font,"Music Playing",color);
    SDL_Surface *msgbmp2 = TTF_RenderText_Blended(font,"Music Paused",color);

    msg1 = SDL_CreateTextureFromSurface(game.renderer, msgbmp1);
    msg2 = SDL_CreateTextureFromSurface(game.renderer, msgbmp2);

    SDL_FreeSurface(msgbmp1);
    SDL_FreeSurface(msgbmp1);

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    bgm = Mix_LoadMUS("BGM/Idecide.mp3");
    bgmPlaying = false;
    Mix_PlayMusic(bgm, -1);

   
}

void Start ::cleanup(void)
{

    Mix_HaltMusic();
    Mix_FreeMusic(bgm);
    Mix_CloseAudio();
    TTF_CloseFont(font);
    SDL_DestroyTexture(bgTexture);
    SDL_DestroyTexture(msg1);
    SDL_DestroyTexture(msg2);
}

void Start ::pause(void)
{
}

void Start ::resume(void)
{
}

void Start ::handleEvents(void)
{
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            game.quit();
            break;
        case SDL_KEYDOWN:
          	game.changeState(&playState);
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

void Start::update(void)
{
    
}

void Start ::draw(void)
{
    SDL_RenderClear(game.renderer);
    SDL_RenderCopy(game.renderer, bgTexture, NULL, NULL);
    
	char str[100];
	SDL_Rect rect2 = {420, 200, 0, 0};
    sprintf(str, "Press any key", no);
    SDL_Color color={0,0,255};
    SDL_Surface *img = TTF_RenderText_Blended(font, str, color);
    SDL_Texture *emsg = SDL_CreateTextureFromSurface(game.renderer, img);
    SDL_QueryTexture(emsg, NULL, NULL, &rect2.w, &rect2.h);
    SDL_RenderCopy(game.renderer, emsg, NULL, &rect2);
    SDL_FreeSurface(img);
    SDL_DestroyTexture(emsg);


    SDL_RenderPresent(game.renderer);
}
