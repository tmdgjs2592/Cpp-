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

float xIncrement, yIncrement;
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

void keyoperations(unsigned char key, int x, int y)
{
	switch(key)
	{
	case'a':
		xIncrement -= 0.02;
		break;
	case'd':
		xIncrement += 0.02;
		break;
	case'w':
		yIncrement += 0.02;
		break;
	case's':
		yIncrement -=0.02;
		break;
	default:
		break;
	}
	glutPostRedisplay();
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
	    }
	    glEnd();

}

void display(){
	glutKeyboardFunc(keyoperations);
	glClear(GL_COLOR_BUFFER_BIT);
	drawMap();
	drawSnake(0.3 + xIncrement, 0.3 + yIncrement, 0.05, 100);
	glFlush();
}

int main(int argc, char** argv) {

   glutInit(&argc, argv);// Initialize GLUT
   //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(750, 750);   // Set the window's initial width & height
   glutInitWindowPosition(500, 50);  // Position the window's initial top-left corner
   glutCreateWindow("Snake Game by John Lee"); // Create a window with the given title

   glutDisplayFunc(display); // Register display callback handler for window re-paint

   glutSwapBuffers();

   glutMainLoop();           // Enter the event-processing loop
   return 0;
}



