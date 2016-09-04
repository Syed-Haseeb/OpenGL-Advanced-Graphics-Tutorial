/*#include <Windows.h>


#include <SDL/SDL.h>
#include <GL/glew.h>



int main(int argc, char** argv)
{

	SDL_Init(SDL_INIT_EVERYTHING);
	return 0;

}*/

#include "MainGame.h"
#include <iostream>

int main(int argc, char** argv)
{
	MainGame mainGame;

	mainGame.run();


	return 0;

}