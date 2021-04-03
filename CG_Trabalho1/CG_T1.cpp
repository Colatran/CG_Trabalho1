#include <windows.h>
#include <gl/glut.h>
#include <math.h>
#include "Map.h"
#include "Entity.h"
#include "Player.h"
#define ORIGIN 125 //500 / 4
#define MAP Map::ref


#include <iostream>
using namespace std;

// Step size in x and y directions (number of pixels to move each time)
GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;
// Timer
GLfloat count_timer = 0;
// Keep track of windows changing width and height
GLfloat windowWidth;
GLfloat windowHeight;


Player *player;





// Called to draw scene
void RenderScene(void)
{
	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT);

	// Draw 
	// Map
	MAP->draw();
	// Entities
	for (int i = 0; i < 50; i++) {
		if (Entity::slots[i]) {
			Entity::entities[i]->draw();
		}
	}

	// Flush drawing commands
	glutSwapBuffers();
}

// Called by GLUT library when idle (window not being
// resized or moved)
void TimerFunction(int value)
{
	// Reverse direction when you reach left or right edge
	/*if (x1 > windowWidth - rsize || x1 < 0)
		xstep = -xstep;
	// Reverse direction when you reach top or bottom edge
	if (y1 > windowHeight - rsize || y1 < 0)
		ystep = -ystep;*/
	for (int i = 0; i < 50; i++) {
		if (Entity::slots[i]) {
			Entity::entities[i]->collision();
		}
	}


	// Move Entities
	for (int i = 0; i < 50; i++) {
		if (Entity::slots[i]) {
			Entity::entities[i]->move();
		}
	}

	//control time
	count_timer++;

	// Redraw the scene with new coordinates
	glutPostRedisplay();
	glutTimerFunc(30, TimerFunction, 1);
}





void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27: exit(0); break;
	case '1': MAP->DecreaseMap(); break;
	case '2': MAP->IncreaseMap(); break;
	case 'w': player->dirY += 1.0f; break;
	case 's': player->dirY += -1.0f; break;
	case 'd': player->dirX += 1.0f; break;
	case 'a': player->dirX += -1.0f; break;
	default: break;
	}
	glutPostRedisplay();
}





// Setup the rendering state
void SetupRC(void)
{
	// Set clear color to blue
	glClearColor(0.0f, 0.8f, 0.8f, 1.0f);
}
// Called by GLUT library when the window has changed size
void ChangeSize(GLsizei w, GLsizei h)
{
	// Prevent a divide by zero
	if (h == 0)
		h = 1;

	// Set Viewport to window dimensions
	glViewport(0, 0, w, h);

	// Reset coordinate system
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Keep the square square, this time, save calculated
	// width and height for later use
	if (w <= h) {
		windowHeight = 250.0f * h / w;
		windowWidth = 250.0f;
	}
	else {
		windowWidth = 250.0f * w / h;
		windowHeight = 250.0f;
	}

	// Set the clipping volume
	glOrtho(0.0f, windowWidth, 0.0f, windowHeight, 1.0f, -1.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Main program entry point
int main(int argc, char** argv) {
	glutInit(&argc, argv);      // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutCreateWindow("EchoLands");

	//Spawn entities
	Map::ref = new Map();
	player = new Player(ORIGIN, ORIGIN);

	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(30, TimerFunction, 1);

	SetupRC();
	glutMainLoop();
}