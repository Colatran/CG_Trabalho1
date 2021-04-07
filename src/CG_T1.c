#include <windows.h>
#include <gl/glut.h>
#include "Draw.h"//

// Timer
GLfloat count_timer = 0;
// Keep track of windows changing width and height
GLfloat windowWidth;
GLfloat windowHeight;

//Map
float map_radius = 70.0f;

//Entities
struct Entity entities[50];
int slots[50] = { 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 };
struct Entity player;





//Utils
float RandomFloat(float min, float max) {
	float random = ((float)rand()) / (float)RAND_MAX;
	float range = max - min;
	return (random * range) + min;
}
struct Vector RandomPosition() {
	float angle = RandomFloat(0, 360);
	float length = RandomFloat(0, map_radius);
	struct Vector vector;
	vector.x = sin(angle) * length + ORIGIN;
	vector.y = cos(angle) * length + ORIGIN;
	return vector;
}

//Map Related
void Map_Draw() {
	glColor3f(0.8f, 0.8f, 0.1f);
	glBegin(GL_TRIANGLE_FAN);
	for (float angle = 0.0f; angle < 2 * 3.14159; angle += 0.1) {
		float x = ORIGIN + sin(angle) * map_radius;
		float y = ORIGIN + cos(angle) * map_radius;
		glVertex2f(x, y);
	}
	glEnd();
}
void Map_Decrease() { 
	if (map_radius > 0) map_radius -= 5.0f;
}
void Map_Increase() { 
	if (map_radius < 120) map_radius += 5.0f;
}

//Entities
int NextFreeSlot() {
	for (int i = 0; i < 100; i++) {
		if (slots[i] == 0) {
			slots[i] = 1;
			return i;
		}
	}
	return 100;
}
void Spawn(struct Entity entity) {
	int slot = NextFreeSlot();
	entities[slot] = entity;
	entities[slot].slot = slot;
}
void Despawn(int index,  int by) {
	slots[index] = 0;
}

// Called to draw scene
void RenderScene(void) {
	glutInitWindowPosition(-125, 125);
	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT);

	// Draw 
	Map_Draw();
	// Entities
	for (int i = 0; i < 50; i++) {
		if (slots[i]) {
			Draw(&entities[i]);
		}
	}
	// Flush drawing commands
	glutSwapBuffers();
}

// Called by GLUT library when idle (window not being resized or moved)
void TimerFunction(int value) {
	//Collision & Movement
	struct Vector vector_origin; vector_origin.x = ORIGIN; vector_origin.y = ORIGIN;
	for (int i1 = 0; i1 < 50; i1++) {
		if (slots[i1]) {
			struct Entity* entity1 = &entities[i1];

			//Check if is outside the map
			if (Distance(&entity1->position, &vector_origin) > map_radius) {
				Despawn(entity1->slot, 0);
				continue;
			}

			switch (entity1->kind) {
			case 0: //Player
			{
				//Movement
				float finalSpeed = entity1->speed * entity1->penaltySpeed * PLAYER_MAXSPEED;
				entity1->position.x += entity1->direction.x * finalSpeed;
				entity1->position.y += entity1->direction.y * finalSpeed;
				entity1->speed = 0;

				//Collision
				for (int i2 = 1; i2 < 50; i2++) { // i2 = 1 porque 0 é o player
					if (slots[i2]) {
						struct Entity* entity2 = &entities[i2];

						if (IsInsideMyBoundries_Circle(entity1, entity2)) {
							switch (entity2->surface) {
							case -2:			//Hit
								Map_Decrease();
								entity1->penaltySpeed = 0;
								break;
							case 3:				//PickUp
								Map_Increase();
								Despawn(entity2->slot, 1);
								break;
							}
						}
					}
				}
			} break;
			case 1: break;
			case 2: //Block
			{
				for (int i2 = 0; i2 < 50; i2++) {
					if (i1 == i2) continue;
					if (slots[i2]) {
						struct Entity* entity2 = &entities[i2];
						struct Vector vector;
						float distance;
						if (IsInsideMyBoundries_Circle(entity1, entity2)) {
							float directionX, directionY;
							switch (entity2->surface) {
							case -1:
							case 0: 
								break;
							case -2:
							case 1:
							case 2:
							case 3:
								vector = SetVectorLength(
									entity2->position.x - entity1->position.x,
									entity2->position.y - entity1->position.y,
									entity1->radius + entity2->radius);
								entity2->position.x = entity1->position.x + vector.x;
								entity2->position.y = entity1->position.y + vector.y;
								break;
							}
						}
					}
				}
			}break;
			}
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
	case '1': Map_Decrease(); break;
	case '2': Map_Increase(); break;
	case 'W': case 'w': entities[0].direction.x = 0;	entities[0].direction.y = 1.0f;	entities[0].speed += 1; break;
	case 'S': case 's': entities[0].direction.x = 0;	entities[0].direction.y = -1.0f;entities[0].speed += 1; break;
	case 'D': case 'd': entities[0].direction.x = 1.0f;	entities[0].direction.y = 0;	entities[0].speed += 1; break;
	case 'A': case 'a': entities[0].direction.x = -1.0f;entities[0].direction.y = 0;	entities[0].speed += 1; break;
	default: break;
	}
	glutPostRedisplay();
}


// Setup the rendering state
void SetupRC(void) {
	// Set clear color to blue
	glClearColor(0.0f, 0.8f, 0.8f, 1.0f);
}
// Called by GLUT library when the window has changed size
void ChangeSize(GLsizei w, GLsizei h) {
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
	/*Spawn(Player());

	Spawn(Block(RandomPosition())); Spawn(Block(RandomPosition())); Spawn(Block(RandomPosition()));
	Spawn(Block(RandomPosition())); Spawn(Block(RandomPosition())); Spawn(Block(RandomPosition()));
	Spawn(Block(RandomPosition())); Spawn(Block(RandomPosition())); Spawn(Block(RandomPosition()));
	Spawn(Block(RandomPosition())); Spawn(Block(RandomPosition())); Spawn(Block(RandomPosition()));
	Spawn(Block(RandomPosition())); Spawn(Block(RandomPosition())); Spawn(Block(RandomPosition()));
	Spawn(PickUp(RandomPosition())); Spawn(PickUp(RandomPosition())); Spawn(PickUp(RandomPosition()));*/

	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(30, TimerFunction, 1);
	
	SetupRC();
	glutMainLoop();
}