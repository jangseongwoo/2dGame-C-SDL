#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include "gamestate.h"

#define C_SWORD 0
#define S_LEFTSTAND 1
#define S_RIGHTWALK 2
#define S_LEFTWALK 3
#define WALK 10
#define ATTACK 11
class Sprite
{
    SDL_Texture *sheetTexture;
    
    int character; // rightStand = 0, leftStand = 1, rightWalking = 2, leftWalking = 3
    int frame;
	int action;
	

public:
	int px, py;
    Sprite(void);
    ~Sprite();
	int hp;
	
	
    void createCharacter(int i);
    void update(void);
    void walk(void);
    void attack(void);
    void draw(void);
};

#endif
