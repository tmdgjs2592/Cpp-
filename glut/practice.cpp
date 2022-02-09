#include <iostream>
#include <windows.h>
#include <vector>
#include <conio.h>
#include <gl/glut.h>
#include <iterator>
#include <algorithm>
#include <math.h>
#include "time.h"
using namespace std;

float x,y, foodX, foodY;
float xIncrement, yIncrement;
bool* keyStates = new bool[256];
bool start = false;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
bool gameOver = false;
bool again = true;

void keyPressed(unsigned char key, int x, int y){
	keyStates[key] = true;
}

//Method to unset the released key
void keyUp(unsigned char key, int x, int y){
	keyStates[key] = false;
}


void firstScreen()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glOrtho(0, 750, 750, 0, -1.0, 1.0);
	glClearColor(184.0f/255.0f, 213.0f/255.0f, 238.0f/255.0f, 1.0f);
		char* message = "----------------------------------";
		glRasterPos2f(150, 200);
		while (*message)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *message++);
		message = "Snake Game by John Lee";
		glColor3f(1, 1, 0);
		glRasterPos2f(260, 300);
		while (*message)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *message++);
		message = "----------------------------------";
		glRasterPos2f(150, 400);
		while (*message)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *message++);
		message = "Click space to start the game";
		glRasterPos2f(235, 500);
		while (*message)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *message++);



}

void keyInput(unsigned char key, int x, int y)
{

	        switch(key)
	        {
	        case 'a':
	            dir=LEFT;
	            Sleep(50);
	            break;
	        case 'w':
	            dir=UP;
	            Sleep(50);
	            break;
	        case 's':
	            dir=DOWN;
	            Sleep(50);
	            break;
	        case 'd':
	            dir=RIGHT;
	            Sleep(50);
	            break;
	        case 'x':
	            gameOver = true;
	            break;
	        case ' ':
	        	start = true;

	        }


}
void keyoperations2()
{
	switch(dir)
	    {
	    case LEFT:
	    	xIncrement -= 0.014;
	    	break;
	    case RIGHT:
	    	xIncrement += 0.014;
	        break;
	    case UP:
	    	yIncrement += 0.014;
	        break;
	    case DOWN:
	    	yIncrement -= 0.014;
	        break;
	    default:
	        break;
	    }
	glutPostRedisplay();
}

void drawMap()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glBegin(GL_QUADS);
	glColor3f(0.84, 0.84, 0.84); // Grey
	glRectf(50,50,50,50);
	glVertex2f(-0.8f, -0.8f);    // x, y, down
	glVertex2f(0.8f, -0.8f); //
	glVertex2f(0.8f, 0.8f);
	glVertex2f(-0.8f, 0.8f); // up
	glEnd();

}

void drawSnake(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	    for(int ii = 0; ii < num_segments; ii++)
	    {
	        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments); //get the current angle, whole circle divided by the number of angles

	        x = r * cosf(theta); //calculate the x component
	        y = r * sinf(theta); //calculate the y component

	        glVertex2f(x + cx, y + cy); //output vertex
	    }
	glEnd();

}

void drawFood()
{
	if(again){
		foodX = (rand() % 800) / 1000.0;
		foodY = (rand() % 800) / 1000.0;
	}
	glPointSize(5.0);
	glBegin(GL_POINTS);
	glColor3f(0, 0, 0);
	glVertex2f(foodX, foodY);
	glEnd();
	again = false;

	if (foodX == x + 0.03 + xIncrement  && foodY == y + 0.03 + yIncrement)
		again=true;
}

void reshape(int w, int h){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glOrtho(0, 750, 750, 0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display(){
	glutKeyboardFunc(keyInput);

	keyoperations2();
	glClear(GL_COLOR_BUFFER_BIT);
	if (start){
		drawMap();
		drawSnake(0.03 + xIncrement, 0.05 + yIncrement, 0.05, 100);
		drawFood();
	}
	else
	{

		firstScreen();
	}

	glutSwapBuffers();
}



int main(int argc, char** argv) {

   glutInit(&argc, argv);// Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(750, 750);   // Set the window's initial width & height
   glutInitWindowPosition(500, 50);  // Position the window's initial top-left corner
   glutCreateWindow("Snake Game by John Lee"); // Create a window with the given title
   //glutReshapeFunc(reshape);

   glutDisplayFunc(display); // Register display callback handler for window re-paint
   glutIdleFunc(display);


   glutMainLoop();           // Enter the event-processing loop
   return 0;
}
