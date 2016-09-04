//#pragma once
//#include <GL/glew.h>
//
//
//class Sprite
//{
//	Sprite();
//	~Sprite();
//
//	void init(float x, float y, float width, float height);
//
//	void draw();
//
//private:
//	float _x;
//	float _y;
//	float _width;
//	float _height;
//
//	//unsigned int guarenteed to be 32 bits (for VBO pointer)
//	GLuint _vboID;
//};

#pragma once
#include <GL/glew.h>
//#include <GL/GLU.h>

//A 2D quad that can be rendered to the screen
class Sprite
{
public:
	Sprite();
	~Sprite();

	void init(float x, float y, float width, float height);

	void draw();

private:
	float _x;
	float _y;
	float _width;
	float _height;
	GLuint _vboID;

};

