#include <windows.h>
#include "Draw.h"
#define PLAYER entities[0]
#define PLAYER_MAXSPEED 3
#define MAX_ENTITIES 100
#define BACKGROUND_COLOR 0.0f, 0.8f, 0.8f

// Timer
GLfloat count_timer = 0;
// Keep track of windows changing width and height
GLfloat windowWidth;
GLfloat windowHeight;

//Map
float map_radius = 70.0f;
struct Vector vector_origin;

//Entities
struct Entity entities[MAX_ENTITIES];
int slots[MAX_ENTITIES];
float player_penaltySpeed = 1;

int level = 0;
int level_isEmpty = 1;
int level_frame = 60;




//Utils
float RandomFloat(float min, float max) {
	float random = ((float)rand()) / (float)RAND_MAX;
	float range = max - min;
	return (random * range) + min;
}
struct Vector RandomPosition() {
	float angle = RandomFloat(0, 360);

	float length = RandomFloat(0, map_radius) *1.5f;
	if (length > map_radius) {
		float difference = length - map_radius;
		length -= difference * 2;
	}
	if (length < map_radius / 10) length *= 10;

	struct Vector vector;
	vector.x = sin(angle) * length + ORIGIN;
	vector.y = cos(angle) * length + ORIGIN;
	return vector;
}

//Map Related
void Map_Draw() {
	//Torre
	for (float angle = 0.01f; angle < 3.14f; angle += 0.01f) {
		glBegin(GL_POLYGON);

		float x, y, percent, color;
		percent = angle / 3.14f;
		glColor3f(0.2f + percent * 0.47f, 0.23f + percent * 0.6f, 0.17f + percent * 0.44f);

		x = ORIGIN + sin(angle + 1.56) * map_radius;
		y = ORIGIN + cos(angle + 1.56) * map_radius;
		glVertex2f(x, y);
		x = ORIGIN + sin(angle + 1.57) * map_radius;
		y = ORIGIN + cos(angle + 1.57) * map_radius;
		glVertex2f(x, y);

		glColor3f(BACKGROUND_COLOR);
		x = ORIGIN + sin(angle + 1.57) * map_radius;
		y = 50 + cos(angle + 1.57) * map_radius;
		glVertex2f(x, y);
		x = ORIGIN + sin(angle + 1.56) * map_radius;
		y = 50 + cos(angle + 1.56) * map_radius;
		glVertex2f(x, y);

		glEnd();
	}

	//Arena
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.3f, 0.3f, 0.3f);
	for (float angle = 0.0f; angle < 6.3; angle += 0.1) {
		float x = ORIGIN + sin(angle) * map_radius;
		float y = ORIGIN + cos(angle) * map_radius - 3;
		glVertex2f(x, y);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.5f, 0.5f, 0.5f);
	for (float angle = 0.0f; angle < 6.3; angle += 0.1) {
		float x = ORIGIN + sin(angle) * map_radius;
		float y = ORIGIN + cos(angle) * map_radius;
		glVertex2f(x, y);
	}
	glEnd();

	float newRadius = map_radius - 4;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.3f, 0.3f, 0.3f);
	for (float angle = 0.0f; angle < 6.3; angle += 0.1) {
		float x = ORIGIN + sin(angle) * newRadius;
		float y = ORIGIN + cos(angle) * newRadius + 1.5;
		glVertex2f(x, y);
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.3f, 0.5f, 0.2f);
	for (float angle = 0.0f; angle < 6.3; angle += 0.1) {
		float x = ORIGIN + sin(angle) * newRadius;
		float y = ORIGIN + cos(angle) * newRadius - 1;
		glVertex2f(x, y);
	}
	glEnd();
}
void Map_Decrease() { 
	if (map_radius > 10) map_radius -= 5.0f;
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
void Despawn(int index, int forLevel) {
	slots[index] = 0;

	if (forLevel) {
		int mapIsEmpty = 1;
		int kind, i;

		for (i = 1; i < MAX_ENTITIES; i++) {
			kind = entities[i].kind;
			if (slots[i]) {
				if (kind > 0 && kind < 5) {
					mapIsEmpty = 0;
					i = MAX_ENTITIES;
				}
			}
		}

		if (mapIsEmpty) level_isEmpty = 1;
	}
}
void LevelUp() {
	if (!slots[0]) return;

	int random, i;
	level++;

	//Limpar obstaculos
	for (i = 1; i < MAX_ENTITIES; i++) {
		if (slots[i]) {
			struct Entity* entity = &entities[i];
			if (entity->kind == 7) {
				Despawn(entity->slot, 0);
			}
		}
	}

	//Inimigos
	for (i = 0; i < level; i++) {
		random = rand() % 3;
		switch (random) {
		case 0:
			Spawn(Thrower(RandomPosition()));
			break;
		case 1:
			Spawn(BlobSmall(RandomPosition()));
			break;
		case 2:
			Spawn(BlobBig(RandomPosition()));
			break;
		}
	}

	//Jarras
	random = rand() % 5;
	for (i = 0; i <= random; i++) {
		Spawn(Jar(RandomPosition()));
	}

	//Obstaculos
	random = rand() % (int)(map_radius / 10);
	for (i = 0; i <= random; i++) {
		Spawn(Block(RandomPosition()));
	}
}



// Called to draw scene
void RenderScene(void) {
	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT);

	// Draw 
	Map_Draw();
	// Entities
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if (slots[i]) {
			Draw(&entities[i]);
		}
	}
	// Flush drawing commands
	glutSwapBuffers();
}

// Called by GLUT library when idle (window not being resized or moved)
void TimerFunction(int value) {
	//Colisao & Movimento & AI & Outros
	for (int i1 = 0; i1 < MAX_ENTITIES; i1++) {
		if (slots[i1]) {
			struct Entity* entity1 = &entities[i1];

			//Caiu do mapa?
			if (Distance(&entity1->position, &vector_origin) > map_radius) {
				if (entity1->kind != 8) { 
					Despawn(entity1->slot, 1);
					if (i1 == 0) Spawn(Player());
				}
			}

			switch (entity1->kind) {
			case 0: {
				//entity1->frame[0] //tempo de ataque
				//entity1->frame[1] //tempo de imobilizado depois de ser atacado
				//entity1->frame[2] //deve ou nao desenha o personagem (efeito de estar himune) 0-visivel 1-invizivel

				//Hit
				if (entity1->health == 0) {
					entity1->health = 1;
					if (entity1->frame_imunity == 0) {
						Map_Decrease();
						player_penaltySpeed = 0;
						entity1->frame_imunity = 30;
						entity1->frame[1] = 10;
						Spawn(Particle(entity1->position, 0, 2));
					}
				}
				if (entity1->frame_imunity > 0) { 
					entity1->frame_imunity--;
					if (entity1->frame_imunity == 0) entity1->frame[2] = 1;
					else {
						if (entity1->frame[2])entity1->frame[2] = 0;
						else entity1->frame[2] = 1;
					}
				}
				if (entity1->frame[1] > 0) { 
					entity1->frame[1]--;
					if (entity1->frame[1] == 0)	player_penaltySpeed = 1;
				}

				//Movimento
				float finalSpeed = entity1->speed * player_penaltySpeed * PLAYER_MAXSPEED;
				entity1->position.x += entity1->direction.x * finalSpeed;
				entity1->position.y += entity1->direction.y * finalSpeed;
				if (entity1->frame[0] > 0) entity1->frame[0]--;
				else entity1->speed = 0;

				//Colisao
				for (int i2 = 1; i2 < MAX_ENTITIES; i2++) { // i2 = 1 porque 0 é o player
					if (slots[i2] && i1 != i2) {
						struct Entity* entity2 = &entities[i2];

						if (IsInsideMyBoundries_Circle(entity1, entity2)) {
							struct Vector vector;
							switch (entity2->surface) {
							case 0: {
								struct Vector vector = SetVectorLength(
									entity1->position.x - entity2->position.x,
									entity1->position.y - entity2->position.y,
									entity2->radius + entity1->radius);
								entity1->position.x = entity2->position.x + vector.x;
								entity1->position.y = entity2->position.y + vector.y;
							} break;
							case 3:
								if (entity2->frame_imunity == 0)entity2->health = 0;
								break; //PickUp
							}
						}
					}
				}
			} break; //Player

			case 1: {
				//Reduzir tempo de imunidade
				if (entity1->frame_imunity > 0) entity1->frame_imunity--;

				//Rotina AI
				//entity1->frame[0] //fase da rotina
				//entity1->frame[1] //tempo da faze da rotina
				switch (entity1->frame[0]) {
				case 0: {
					//Procura ponto aleatorio
					entity1->AIpoint = RandomPosition();
					entity1->direction = SetVectorLength(entity1->AIpoint.x - entity1->position.x, entity1->AIpoint.y - entity1->position.y, 1.0);
					entity1->speed = 4.0f;
					entity1->frame[0]++;
				} break;
				case 1: {
					//Vai para la
					entity1->position.x += entity1->direction.x * entity1->speed;
					entity1->position.y += entity1->direction.y * entity1->speed;
					//Ve se chegou
					entity1->frame[1]++;
					if (entity1->frame[1] >= 60 ||	// tem 2 segundos para chegar ao destino
						Distance(&entity1->position, &entity1->AIpoint) < 20.0) {	// esta no destino
						entity1->speed = 0;
						entity1->frame[1] = 0;
						entity1->frame[0]++;
					}
				} break;
				case 2: {
					//Espera 1s
					entity1->frame[1]++;
					if (entity1->frame[1] >= 30) {
						entity1->frame[1] = 0;
						entity1->frame[0]++;
					}
				} break;
				case 3: {
					//Atira pedra
					entity1->frame[0]++;
					Spawn(ThrowerRock(
						entity1->position,
						SetVectorLength(PLAYER.position.x - entity1->position.x, PLAYER.position.y - entity1->position.y, 1.0)
					));
				} break;
				case 4: {
					//Espera 1s
					entity1->frame[1]++;
					if (entity1->frame[1] >= 30) {
						entity1->frame[1] = 0;
						entity1->frame[0] = 0;
					}
				} break;
				}

				//Colisao
				for (int i2 = 1; i2 < MAX_ENTITIES; i2++) { // i2 = 1 porque 0 é o player
					if (slots[i2] && i1 != i2) {
						struct Entity* entity2 = &entities[i2];

						if (IsInsideMyBoundries_Circle(entity1, entity2)) {
							switch (entity2->surface) {
							case 0: {
								struct Vector vector = SetVectorLength(
									entity1->position.x - entity2->position.x,
									entity1->position.y - entity2->position.y,
									entity2->radius + entity1->radius);
								entity1->position.x = entity2->position.x + vector.x;
								entity1->position.y = entity2->position.y + vector.y; 
							} break;
							case -1: {			//Hit
								if (entity1->frame_imunity == 0) {
									Spawn(Particle(entity1->position, 0, 2));
									entity1->health--;
									if (entity1->health <= 0) Despawn(entity1->slot, 1);
									else entity1->frame_imunity = 5;
								}
							} break;
							}
						}
					}
				}
			} break; //Enemy thrower
			
			case 2: {
				//Movimento
				entity1->position.x += entity1->direction.x * entity1->speed;
				entity1->position.y += entity1->direction.y * entity1->speed;

				//Colisao
				for (int i2 = 0; i2 < MAX_ENTITIES; i2++) {
					if (slots[i2] && i1 != i2) {
						struct Entity* entity2 = &entities[i2];

						if (IsInsideMyBoundries_Circle(entity1, entity2)) {
							switch (entity2->surface) {
							case 0:
							case 1:
								entity2->health = 0;
							case -1:
								Despawn(entity1->slot, 1);
								break;
							}
						}
					}
				}
			} break; //Enemy thrower rock
				
			case 3: {
				//Rotina AI
				//entity1->frame[0] //fase da rotina
				//entity1->frame[1] //tempo da faze da rotina
				//entity1->frame[2] //se causa ou nao dano
				//entity1->frame_imunity //else salta 3 vezes segidas so depois espera 1 s
				switch (entity1->frame[0]) {
				case 0: {
					//Encontra a direcao para o jogador
					entity1->direction = SetVectorLength(entities[0].position.x - entity1->position.x, entities[0].position.y - entity1->position.y, 1.0);
					entity1->speed = 7.5f;
					entity1->frame[0]++;
					entity1->frame[2] = 1;
				} break;
				case 1: {
					//Atira-se para la
					entity1->position.x += entity1->direction.x * entity1->speed;
					entity1->position.y += entity1->direction.y * entity1->speed;
					//Durante 5 frames
					entity1->frame[1]--;
					if(entity1->frame[1] == 0){
						//Passa para a proxima faze da rotina
						entity1->frame[0]++;

						//Adiciona um salto ou reseta
						entity1->frame_imunity++;
						if (entity1->frame_imunity == 3) entity1->frame_imunity = 0;

						//Se ja for o 3o salto espera 60 frames, se nao apenas 10
						if(entity1->frame_imunity == 0) entity1->frame[1] = 60;
						else entity1->frame[1] = 10;

						//so ataca o player se estiver no salto
						entity1->frame[2] = 0;
						entity1->speed = 0.0f;
					}
				} break;
				case 2: {
					//Atraso entre salto
					entity1->frame[1]--;
					if (entity1->frame[1] == 0) {
						entity1->frame[0] = 0;
						entity1->frame[1] = 5;
					}
				} break;
				}

				//Colisao
				for (int i2 = 0; i2 < MAX_ENTITIES; i2++) { // i2 = 1 porque 0 é o player
					if (slots[i2] && i1 != i2) {
						struct Entity* entity2 = &entities[i2];

						if (IsInsideMyBoundries_Circle(entity1, entity2)) {
							switch (entity2->surface) {
							case 0: {
								struct Vector vector = SetVectorLength(
									entity1->position.x - entity2->position.x,
									entity1->position.y - entity2->position.y,
									entity2->radius + entity1->radius);
								entity1->position.x = entity2->position.x + vector.x;
								entity1->position.y = entity2->position.y + vector.y;
							} break;
							case -1: {//Hit
								if (entity1->frame_imunity == 0) {
									Spawn(Particle(entity1->position, 0, 2));
									entity1->health--;
									if (entity1->health <= 0) Despawn(entity1->slot, 1);
									else entity1->frame_imunity = 5;
								}
							} break;
							case 1:
								if (entity1->frame[2] == 1) {
									entity2->health = 0;
								}
								break;
							}
						}
					}
				}

			} break; //Enemy blob small

			case 4: {
				//Reduzir tempo de imunidade
				if (entity1->frame_imunity > 0) entity1->frame_imunity--;

				//Rotina AI
				//entity1->frame[0] //fase da rotina
				//entity1->frame[1] //tempo da faze da rotina
				//entity1->frame[2] //se causa ou nao dano
				switch (entity1->frame[0]) {
				case 0: {
					//Encontra a direcao para o jogador
					entity1->direction = SetVectorLength(entities[0].position.x - entity1->position.x, entities[0].position.y - entity1->position.y, 1.0);
					entity1->speed = 10.0f;
					entity1->frame[0]++;
					entity1->frame[2] = 1;
				} break;
				case 1: {
					//Atira-se para la
					entity1->position.x += entity1->direction.x * entity1->speed;
					entity1->position.y += entity1->direction.y * entity1->speed;
					//Durante 5 frames
					entity1->frame[1]--;
					if (entity1->frame[1] == 0) {
						//Passa para a proxima faze da rotina
						entity1->frame[0]++;

						//Espera 60 frames ate ao proximo salto
						entity1->frame[1] = 60;

						//so ataca o player se estiver no salto
						entity1->frame[2] = 0;
						entity1->speed = 0.0f;
					}
				} break;
				case 2: {
					//Atraso entre salto
					entity1->frame[1]--;
					if (entity1->frame[1] == 0) {
						entity1->frame[0] = 0;
						entity1->frame[1] = 10;
					}
				} break;
				}

				//Colisao
				for (int i2 = 0; i2 < MAX_ENTITIES; i2++) { // i2 = 1 porque 0 é o player
					if (slots[i2] && i1 != i2) {
						struct Entity* entity2 = &entities[i2];

						if (IsInsideMyBoundries_Circle(entity1, entity2)) {
							switch (entity2->surface) {
							case 0: {
								struct Vector vector = SetVectorLength(
									entity1->position.x - entity2->position.x,
									entity1->position.y - entity2->position.y,
									entity2->radius + entity1->radius);
								entity1->position.x = entity2->position.x + vector.x;
								entity1->position.y = entity2->position.y + vector.y;
							} break;
							case -1: {//Hit
								if (entity1->frame_imunity == 0) {
									Spawn(Particle(entity1->position, 0, 2));
									entity1->health--;
									if (entity1->health <= 0) Despawn(entity1->slot, 1);
									else entity1->frame_imunity = 5;
								}
							} break;
							case 1:
								if (entity1->frame[2] == 1) {
									entity2->health = 0;
								}
								break;
							}
						}
					}
				}

			} break; //Enemy blob big

			case 5: {
				if (entity1->frame_imunity > 0) entity1->frame_imunity--;
				else if(entity1->health == 0) {
					Map_Increase();
					Despawn(entity1->slot, 0);
				}
			} break; //PickUp

			case 6: {
				if (entity1->health == 0) {
					Spawn(PickUp(entity1->position));
					Despawn(entity1->slot, 0);
				}
			} break; //Jar

			//case 7: {} break; //Block

			case 8: {
				//Tempo
				entity1->frame[0]++;
				if (entity1->frame[0] > 3) {
					Despawn(entity1->slot, 0);
				}

				//Movimento
				entity1->position.x = PLAYER.position.x + entity1->direction.x * PLAYER.radius;
				entity1->position.y = PLAYER.position.y + entity1->direction.y * PLAYER.radius;

				//Colisao
				for (int i2 = 0; i2 < MAX_ENTITIES; i2++) {
					if (slots[i2] && i1 != i2) {
						struct Entity* entity2 = &entities[i2];

						if (IsInsideMyBoundries_Circle(entity1, entity2)) {
							if (entity2->kind == 6) {
								entity2->health = 0;
							}
						}
					}
				}
			} break; //Player Sword

			case 9: {
				entity1->frame_imunity--;
				if (entity1->frame_imunity  == 0) {
					Despawn(entity1->slot, 0);
				}			
			} break; //Particle
			}
		}
	}

	//Intervalo entre niveis
	if (level_isEmpty) { 
		level_frame--;
		if (level_frame == 0) {
			level_isEmpty = 0;
			level_frame = 60;
			LevelUp();
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
	case 'W': case 'w': if (PLAYER.frame[0] == 0) { PLAYER.direction.x = 0;	PLAYER.direction.y = 1.0f;	PLAYER.speed += 1; } break;
	case 'S': case 's': if (PLAYER.frame[0] == 0) { PLAYER.direction.x = 0;	PLAYER.direction.y = -1.0f; PLAYER.speed += 1; } break;
	case 'D': case 'd': if (PLAYER.frame[0] == 0) { PLAYER.direction.x = 1.0f;	PLAYER.direction.y = 0;	PLAYER.speed += 1; } break;
	case 'A': case 'a': if (PLAYER.frame[0] == 0) { PLAYER.direction.x = -1.0f; PLAYER.direction.y = 0;	PLAYER.speed += 1; } break;
	case 'C': case 'c': if (PLAYER.frame[0] == 0) { Spawn(PlayerSword(PLAYER)); PLAYER.frame[0] = 3;	PLAYER.speed += 1;	} break;
	default: break;
	}
	glutPostRedisplay();
}


// Setup the rendering state
void SetupRC(void) {
	// Set clear color to blue
	glClearColor(BACKGROUND_COLOR, 1.0f);
}
// Called by GLUT library when the window has changed size
void ChangeSize(GLsizei w, GLsizei h) {
	// Prevent a divide by zero
	if (h == 0) h = 1;

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
	glOrtho(0.0f, windowWidth, 0.0f, windowHeight, 0.0f, -250.0f);
	//glOrtho(0.0f, windowWidth, 0.0f, windowHeight, 1.0f, -1.0f);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Main program entry point
int main(int argc, char** argv) {
	glutInit(&argc, argv);      // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(125, 125);
	glutCreateWindow("EchoLands");

	vector_origin.x = ORIGIN;
	vector_origin.y = ORIGIN;

	//Spawn entities
	Spawn(Player());



	/*struct Vector vetor;
	for (int i1 = 1; i1 < 5; i1++) {
		vetor.y = i1 * 10 + ORIGIN;
		for (int i2 = 1; i2 < 5; i2++) {
			vetor.x = i2 * 10+ ORIGIN;
			Spawn(Jar(vetor));
		}
	}
	for (int i1 = -1; i1 > -5; i1--) {
		vetor.y = i1 * 10 + ORIGIN;
		for (int i2 = 1; i2 < 5; i2++) {
			vetor.x = i2 * 10 + ORIGIN;
			Spawn(Jar(vetor));
		}
	}*/



	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(30, TimerFunction, 1);
	
	SetupRC();
	glutMainLoop();
}
