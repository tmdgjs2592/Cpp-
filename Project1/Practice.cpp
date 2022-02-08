/*
 * Practice.cpp
 *
 *  Created on: Feb 7, 2022
 *      Author: tmdgj
 */
#include <iostream>
#include <windows.h>
#include <vector>
#include <gl/glut.h>
#include <iterator>
#include <algorithm>
#include <math.h>
using namespace std;

int xIncrement, yIncrement;
bool* keyStates = new bool[256];

void keyPressed(unsigned char key, int x, int y){
	keyStates[key] = true;
}

//Method to unset the released key
void keyUp(unsigned char key, int x, int y){
	keyStates[key] = false;
}

void drawMap()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
	glColor3f(0.84f, 0.84f, 0.84f); // Grey
	glVertex2f(-0.8f, -0.8f);    // x, y, down
	glVertex2f(0.8f, -0.8f); //
	glVertex2f(0.8f, 0.8f);
	glVertex2f(-0.8f, 0.8f); // up
	glEnd();

	glFlush();
}

void keyoperations()
{
	if(keyStates['a'])
		xIncrement = -0.05;
	if(keyStates['d'])
			xIncrement = 0.05;
	if(keyStates['w'])
			yIncrement = -0.05;
	if(keyStates['d'])
			yIncrement = 0.05;
}

void drawSnake(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	    for(int ii = 0; ii < num_segments; ii++)
	    {
	        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments); //get the current angle, whole circle divided by the number of angles

	        float x = r * cosf(theta); //calculate the x component
	        float y = r * sinf(theta); //calculate the y component

	        glVertex2f(x + cx, y + cy); //output vertex

	    }c
	    glEnd();
	    glFlush();
}


void display(){
	keyoperations();
	drawMap();
	drawSnake(0.3 + xIncrement, 0.3 + yIncrement, 0.05, 100);

}

int main(int argc, char** argv) {
   glutInit(&argc, argv);// Initialize GLUT
   //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    // Create a window with the given title
   glutInitWindowSize(750, 750);   // Set the window's initial width & height
   glutInitWindowPosition(500, 50);
   glutCreateWindow("OpenGL Snake"); // Position the window's initial top-left corner
   glutDisplayFunc(display); // Register display callback handler for window re-paint
   glutKeyboardFunc(keyPressed);
   glutKeyboardUpFunc(keyUp);
   glutMainLoop();           // Enter the event-processing loop
   return 0;
}



