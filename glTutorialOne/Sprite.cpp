//#include "Sprite.h"
//
//Sprite::Sprite()
//{
//
//	_vboID = 0;
//}
//
//
//Sprite::~Sprite()
//{
//	if (_vboID != 0)
//	{
//		glDeleteBuffers(1, &_vboID);
//	}
//
//}
//
//void Sprite::init(float x, float y, float width, float height)
//{
//	_x = x;
//	_y = y;
//	_width = width;
//	_height = height;
//
//
//	if (_vboID == 0)
//	{
//		glGenBuffers(1, &_vboID);
//	}
//
//	float vertexData[12]; //6 vertices (x,y coordinates)
//
//
//	//First Triangle
//	vertexData[0] = x + width;
//	vertexData[1] = y + width;
//
//	vertexData[2] = x;
//	vertexData[3] = y + height;
//
//	vertexData[4] = x;
//	vertexData[5] = y;
//
//
//	//Second Triangle
//	vertexData[6] = x;
//	vertexData[7] = y;
//
//	vertexData[8] = x + width;
//	vertexData[9] = y;
//
//	vertexData[10] = x + width;
//	vertexData[11] = y + height;
//
//
//	glBindBuffer(GL_ARRAY_BUFFER, _vboID);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
//
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//}
//
//void Sprite::draw()
//{
//	//tell OpenGl which buffer is active
//	glBindBuffer(GL_ARRAY_BUFFER, _vboID);
//
//	//Enable vertex attribute array
//	glEnableVertexAttribArray(0);
//
//	//point OpenGL to vertex data we want to draw
//	//glVertexAttribPointer(GLuint (which vertex index) , 
//	    //size ( of vertex # elements), GLenum (type of vertex data ), GLboolean (More later..) , GLsizei (stride) , const void *pointer (don't care not interleaved) )
//	glVertexAttribPointer(0, 2, GL_FLOAT,GL_FALSE, 0, 0);
//
//	//Now we just draw (TRIANGLES, start at vertex 0, draw 6 vertices)
//	glDrawArrays(GL_TRIANGLES, 0, 6);
//
//	//disable vertex attribute array
//	glDisableVertexAttribArray(0);
//
//	//unbind buffer at the end
//	glBindBuffer(GL_ARRAY_BUFFER, _vboID);
//}

#include "Sprite.h"


Sprite::Sprite()
{
	//Always initialize your buffer IDs to 0
	_vboID = 0;
}


Sprite::~Sprite()
{
	//Always remember to delete your buffers when
	//you are done!
	if (_vboID != 0) {
		glDeleteBuffers(1, &_vboID);
	}
}

//Initializes the sprite VBO. x, y, width, and height are
//in the normalized device coordinate space. so, [-1, 1]
void Sprite::init(float x, float y, float width, float height) {
	//Set up our private vars
	_x = x;
	_y = y;
	_width = width;
	_height = height;

	//Generate the buffer if it hasn't already been generated
	if (_vboID == 0) {
		glGenBuffers(1, &_vboID);
	}

	//This array will hold our vertex data.
	//We need 6 vertices, and each vertex has 2
	//floats for X and Y
	float vertexData[12];

	//First Triangle
	vertexData[0] = x + width;
	vertexData[1] = y + height;

	vertexData[2] = x;
	vertexData[3] = y + height;

	vertexData[4] = x;
	vertexData[5] = y;

	//Second Triangle
	vertexData[6] = x;
	vertexData[7] = y;

	vertexData[8] = x + width;
	vertexData[9] = y;

	vertexData[10] = x + width;
	vertexData[11] = y + height;

	//Tell opengl to bind our vertex buffer object
	glBindBuffer(GL_ARRAY_BUFFER, _vboID);
	//Upload the data to the GPU
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

	//Unbind the buffer (optional)
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

//Draws the sprite to the screen
void Sprite::draw() {

	//bind the buffer object
	glBindBuffer(GL_ARRAY_BUFFER, _vboID);

	//Tell opengl that we want to use the first
	//attribute array. We only need one array right
	//now since we are only using position.
	glEnableVertexAttribArray(0);

	//Point opengl to the data in our VBO. We will learn
	//more on this later
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

	//Draw the 6 vertices to the screen
	glDrawArrays(GL_TRIANGLES, 0, 6);

	//Disable the vertex attrib array. This is not optional.
	glDisableVertexAttribArray(0);

	//Unbind the VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}