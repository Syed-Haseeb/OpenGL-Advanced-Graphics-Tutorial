#include "MainGame.h"
#include <string>
#include <iostream>


//Error Checking
void fatalError(std::string errorString){

	std::cout << errorString << std::endl;
	std::cout << "Enter any key to quit..." << std::endl;
	int tmp;
	std::cin >> tmp;
	SDL_Quit();
	exit(1);
}


MainGame::MainGame()
{
	_window = nullptr;
	_screenWidth = 1024;
	_screenHeight = 768;
	_gameState = GameState::PLAY;
}

MainGame::~MainGame()
{

}

void MainGame::run()
{
	initSystems();


	//wont usually hardcode in run loop
	_sprite.init(-1.0f, -1.0f, -1.0f, 1.0f);


	gameLoop();
}

void MainGame::initSystems()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	_window = SDL_CreateWindow("Haseeb is learning OpenGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);

	if (_window == nullptr)
	{
		fatalError("SDL window could not be created");
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(_window);

	if (glContext == nullptr){

		fatalError("SDL_GL context could not be created!");
	}

	GLenum error = glewInit();

	if (error != GLEW_OK)
	{
		fatalError("Could not render");

	}


	//set an OpenGL window attribute before window creation
	//essentially gives us two canvases
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}


//event Structure
void MainGame::processInput()
{
	SDL_Event evnt; 


	while (SDL_PollEvent(&evnt))
	{
		switch (evnt.type){
			case SDL_QUIT:
				_gameState = GameState::EXIT;
				break;

			case SDL_MOUSEMOTION:
				std::cout << evnt.motion.x << " " << evnt.motion.y << std::endl; 
				break;

		}

	}
}


void MainGame::drawGame()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glEnableClientState(GL_COLOR_ARRAY);

	//Immediate mode method
	//function calls to draw start here
	//glBegin(GL_TRIANGLES);
	//
	///*glColor3f(0.0f, 1.0f, 1.0f);
	//glVertex2f(0, 0);
	//glVertex2f(0, 500);
	//glVertex2f(500, 500);*/
	//
	////function call to draw end here
	//glEnd();


	//New method (Retained mode?)
	_sprite.draw();

	//Swap buffer and draw everything to the screen!
	SDL_GL_SwapWindow(_window);

}


void MainGame::gameLoop()
{
	while (_gameState != GameState::EXIT)
	{
		processInput();
		drawGame();
		
	}

}