//RVieira OpenGL FreeGlute / Glew C / C++ Setup
#include <GL/glew.h>    
#include <GL/glut.h>    // GLUT, includes glu.h and gl.h
#include <math.h>
#include <time.h>
#include <Windows.h>
// Keep track of windows changing width and height
GLfloat windowWidth;
GLfloat windowHeight;

// Player Values
GLfloat player_x = 125;
GLfloat player_y = 125;

// CPU Values 
// CPU 1 
GLfloat cpu1_x = 40.0f;
GLfloat	cpu1_y = 80.0f;
GLfloat cpu1_xstep = 2.0f;
GLfloat cpu1_ystep = 2.0f;

// CPU 2 
GLfloat cpu2_x = 100.0f;
GLfloat	cpu2_y = 70.0f;
GLfloat cpu2_xstep = 2.0f;
GLfloat cpu2_ystep = 2.0f;

// CPU 3
GLfloat cpu3_x = 220.0f;
GLfloat	cpu3_y = 150.0f;
GLfloat cpu3_xstep = 2.0f;
GLfloat cpu3_ystep = 2.0f;

// Map Values
GLfloat map_x1 = 20;
GLfloat map_y1 = 20;
GLfloat map_rsize = 210;

// Item Values
int item = 1;
GLfloat item_x;
GLfloat item_y;
GLint scoreCounter = 0;

//timer
GLfloat count_timer = 0;

void drawPlayer(void) {
	float radius = 6;
	glColor3f(0.1, 0.2, 0.1);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(player_x, player_y);		// Center coordinates
	for (float angle = 0.0f; angle < 2 * 3.14159; angle += 1) {
		float x2 = player_x + sin(angle) * radius;
		float y2 = player_y + cos(angle) * radius;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void drawCPU1(void) {
	float radius = 10;
	glColor3f(0, 0, 1);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(cpu1_x, cpu1_y);
	for (float angle = 0.0f; angle < 2 * 3.14159; angle += 1) {
		float x2 = cpu1_x + sin(angle) * radius;
		float y2 = cpu1_y + cos(angle) * radius;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void drawCPU2(void) {
	float radius = 10;
	glColor3f(0, 1, 1);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(cpu2_x, cpu2_y);
	for (float angle = 0.0f; angle < 2 * 3.14159; angle += 1) {
		float x3 = cpu2_x + sin(angle) * radius;
		float y3 = cpu2_y + cos(angle) * radius;
		glVertex2f(x3, y3);
	}
	glEnd();
}

void drawCPU3(void) {
	float radius = 10;
	glColor3f(1, 0, 1);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(cpu3_x, cpu3_y);
	for (float angle = 0.0f; angle < 2 * 3.14159; angle += 1) {
		float x2 = cpu3_x + sin(angle) * radius;
		float y2 = cpu3_y + cos(angle) * radius;
		glVertex2f(x2, y2);
	}
	glEnd();

}


void drawMap(void) {
	glColor3f(1, 1, 0);
	glRectf(map_x1, map_y1, map_x1 + map_rsize, map_y1 + map_rsize);
}

void random(void) {
	srand((unsigned int)time(NULL));
	item_x = 50 + rand() % (150);
	item_y = 50 + rand() % (150);
}

void drawItem(void) {
	if (item == 1) {
		random();
	}
	item = 0;
	glColor3f(0, 1, 0);
	glRectf(item_x, item_y, item_x + 5, item_y + 5);
}

void display() {

	float player_cp1_distance = sqrt(((player_x - cpu1_x) * (player_x - cpu1_x)) + ((player_y - cpu1_y) * (player_y - cpu1_y)));
	float player_cp2_distance = sqrt(((player_x - cpu2_x) * (player_x - cpu2_x)) + ((player_y - cpu2_y) * (player_y - cpu2_y)));
	float player_cp3_distance = sqrt(((player_x - cpu3_x) * (player_x - cpu3_x)) + ((player_y - cpu3_y) * (player_y - cpu3_y)));

	glClearColor(0.0, 0.0, 1, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Player Map Collision
	if (player_x + 6 > map_x1 + map_rsize || player_x - 6 < map_x1 || player_y + 6 > map_y1 + map_rsize || player_y - 6 < map_y1) {
		exit(99);
	}

	// Player CPU Collision
	if (player_cp1_distance <= 16 || player_cp2_distance <= 16 || player_cp3_distance <= 16) {
		exit(98);
	}

	// Item Collision Detection
	if (item_x < player_x + 6 && player_x - 6 < item_x + 5 && item_y < player_y + 6 && player_y - 6 < item_y + 6) {
		item = 1;
		scoreCounter++;
	}

	drawMap();
	drawCPU1();
	drawCPU2();
	drawCPU3();
	drawPlayer();
	drawItem();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27:	//Press ESQ to exit
		exit(0);
		break;
	case 'd':
		player_x += 3;
		break;
	case 'a':
		player_x += -3;
		break;
	case 'w':
		player_y += 3;
		break;
	case 's':
		player_y += -3;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

// Called by GLUT library when idle (window not being
// resized or moved)
void TimerFunction(int value)
{
	// Reverse direction when you reach left or right edge
	if (cpu1_x + 10 > map_x1 + map_rsize || cpu1_x - 10 < map_x1) {
		cpu1_xstep = -cpu1_xstep;
	}

	// Reverse direction when you reach top or bottom edge
	if (cpu1_y + 10 >= map_y1 + map_rsize || cpu1_y - 10 < map_y1) {
		cpu1_ystep = -cpu1_ystep;
	}

	// Reverse direction when you reach left or right edge
	if (cpu2_x + 10 >= map_x1 + map_rsize || cpu2_x - 10 < map_x1) {
		cpu2_xstep = -cpu2_xstep;
	}

	// Reverse direction when you reach top or bottom edge
	if (cpu2_y + 10 >= map_y1 + map_rsize || cpu2_y - 10 < map_y1) {
		cpu2_ystep = -cpu2_ystep;
	}

	// Reverse direction when you reach left or right edge
	if (cpu3_x + 10 >= map_x1 + map_rsize || cpu3_x - 10 < map_x1) {
		cpu3_xstep = -cpu3_xstep;
	}

	// Reverse direction when you reach top or bottom edge
	if (cpu3_y + 10 >= map_y1 + map_rsize || cpu3_y - 10 < map_y1) {
		cpu3_ystep = -cpu3_ystep;
	}

	float cpu1_cpu2_distance = sqrt(((cpu1_x - cpu2_x) * (cpu1_x - cpu2_x)) + ((cpu1_y - cpu2_y) * (cpu1_y - cpu2_y)));
	float cpu1_cpu3_distance = sqrt(((cpu1_x - cpu3_x) * (cpu1_x - cpu3_x)) + ((cpu1_y - cpu3_y) * (cpu1_y - cpu3_y)));
	float cpu2_cpu3_distance = sqrt(((cpu2_x - cpu3_x) * (cpu2_x - cpu3_x)) + ((cpu2_y - cpu3_y) * (cpu2_y - cpu3_y)));


	// CPU1 - CPU-2 Collision
	if (cpu1_cpu2_distance <= 20) {
		cpu1_xstep = -cpu1_xstep;
		cpu1_ystep = -cpu1_ystep;
		cpu2_xstep = -cpu2_xstep;
		cpu2_ystep = -cpu2_ystep;
	}

	if (cpu1_cpu3_distance <= 20) {
		cpu1_xstep = -cpu1_xstep;
		cpu1_ystep = -cpu1_ystep;
		cpu3_xstep = -cpu3_xstep;
		cpu3_ystep = -cpu3_ystep;
	}

	if (cpu2_cpu3_distance <= 20) {
		cpu2_xstep = -cpu2_xstep;
		cpu2_ystep = -cpu2_ystep;
		cpu3_xstep = -cpu3_xstep;
		cpu3_ystep = -cpu3_ystep;
	}

	// Move the CPU
	cpu1_x += cpu1_xstep;
	cpu1_y += cpu1_ystep;

	cpu2_x += cpu2_xstep;
	cpu2_y += cpu2_ystep;

	cpu3_x += cpu3_xstep;
	cpu3_y += cpu3_ystep;


	//control time
	count_timer++;

	// Redraw the scene with new coordinates
	glutPostRedisplay();
	glutTimerFunc(1000 / 30, TimerFunction, 1);
}

// Called by GLUT library when the window has changed size
void ChangeSize(GLsizei width, GLsizei height)
{
	// Prevent a divide by zero
	if (height == 0)
		height = 1;

	// Set Viewport to window dimensions
	glViewport(0, 0, width, height);

	// Reset coordinate system
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Keep the square square, this time, save calculated
	// width and height for later use
	if (width <= height) {
		windowHeight = 250.0f * height / width;
		windowWidth = 250.0f;
	}
	else {
		windowWidth = 250.0f * width / height;
		windowHeight = 250.0f;
	}

	// Set the clipping volume
	glOrtho(0, windowWidth, 0, windowHeight, 1.0f, -1.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("EchoLands");

	glutDisplayFunc(display);
	glutReshapeFunc(ChangeSize);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(30, TimerFunction, 1);
	glutMainLoop();

	return 0;
}