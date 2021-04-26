#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include "Draw.h"
#define PLAYER entities[0]
#define PLAYER_MAXSPEED 3
#define MAX_ENTITIES 100
#define BACKGROUND_COLOR 0.0f, 0.8f, 0.8f
#define ARENA_Z 250

// Timer
GLfloat count_timer = 0;

// Keep track of windows changing width and height
GLfloat windowWidth;
GLfloat windowHeight;

//Map
float map_radius = 70.0f;
struct Vector vector_origin;
int level = 0;
int level_isEmpty = 1;
int level_frame = 60;

//Entities
struct Entity entities[MAX_ENTITIES];
int slots[MAX_ENTITIES];
float player_penaltySpeed = 1;

int isLost = 0;
int best_score = 0;
int running = 0; //oposto de pause
int finst = 1; //primeira instrucao
int fullScreen = 1;



//Utils
float RandomFloat(float min, float max) {
	float random = ((float)rand()) / (float)RAND_MAX;
	float range = max - min;
	return (random * range) + min;
}
struct Vector RandomPosition() {
	float angle = RandomFloat(0, 360);

	float length = RandomFloat(0, map_radius) * 1.5f;
	if (length > map_radius) {
		float difference = length - map_radius;
		length -= difference * 2;
	}
	if (length < map_radius / 10) length *= 10;

	struct Vector vector;
	vector.x = sin(angle) * length;
	vector.y = cos(angle) * length;
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

		x = sin(angle + 1.56) * map_radius;
		y = cos(angle + 1.56) * map_radius;
		glVertex3f(x, y, ARENA_Z);
		x = sin(angle + 1.57) * map_radius;
		y = cos(angle + 1.57) * map_radius;
		glVertex3f(x, y, ARENA_Z);

		glColor3f(BACKGROUND_COLOR);
		x = sin(angle + 1.57) * map_radius;
		y = -50 + cos(angle + 1.57) * map_radius;
		glVertex3f(x, y, ARENA_Z);
		x = sin(angle + 1.56) * map_radius;
		y = -50 + cos(angle + 1.56) * map_radius;
		glVertex3f(x, y, ARENA_Z);

		glEnd();
	}

	//Arena
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.3f, 0.3f, 0.3f);
	for (float angle = 0.0f; angle < 6.3; angle += 0.1) {
		float x = sin(angle) * map_radius;
		float y = cos(angle) * map_radius - 3;
		glVertex3f(x, y, ARENA_Z);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.5f, 0.5f, 0.5f);
	for (float angle = 0.0f; angle < 6.3; angle += 0.1) {
		float x = sin(angle) * map_radius;
		float y = cos(angle) * map_radius;
		glVertex3f(x, y, ARENA_Z);
	}
	glEnd();

	float newRadius = map_radius - 4;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.3f, 0.3f, 0.3f);
	for (float angle = 0.0f; angle < 6.3; angle += 0.1) {
		float x = sin(angle) * newRadius;
		float y = cos(angle) * newRadius + 1.5;
		glVertex3f(x, y, ARENA_Z);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.3f, 0.5f, 0.2f);
	for (float angle = 0.0f; angle < 6.3; angle += 0.1) {
		float x = sin(angle) * newRadius;
		float y = cos(angle) * newRadius - 1;
		glVertex3f(x, y, ARENA_Z);
	}
	glEnd();
}
void Map_Decrease() {
	if (map_radius > 10) map_radius -= 5.0f;
}
void Map_Increase() {
	if (map_radius < 120) map_radius += 5.0f;
}

void Draw_TorreFundo(float radius, float xOrigin, float yOrigin, float height) {
	//Torre
	for (float angle = 0.15f; angle < 3.14f; angle += 0.15f) {
		glBegin(GL_POLYGON);

		float x, y, percent, color;
		percent = angle / 3.14f;
		glColor3f(0.59f + percent * 0.08f, 0.87f + percent * 0.05f, 0.77f + percent * 0.03f);

		x = xOrigin + sin(angle + 1.42) * radius;
		y = yOrigin + cos(angle + 1.42) * radius / 1.5;
		glVertex3f(x, y, ARENA_Z);
		x = xOrigin + sin(angle + 1.57) * radius;
		y = yOrigin + cos(angle + 1.57) * radius / 1.5;
		glVertex3f(x, y, ARENA_Z);

		glColor3f(BACKGROUND_COLOR);
		x = xOrigin + sin(angle + 1.57) * radius;
		y = height + cos(angle + 1.57) * radius / 1.5;
		glVertex3f(x, y, ARENA_Z);
		x = xOrigin + sin(angle + 1.42) * radius;
		y = height + cos(angle + 1.42) * radius / 1.5;
		glVertex3f(x, y, ARENA_Z);

		glEnd();
	}

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.59f, 0.87f, 0.77f);
	for (float angle = 0.0f; angle < 6.3; angle += 0.1) {
		float x = xOrigin + sin(angle) * radius;
		float y = yOrigin + cos(angle) * radius / 1.5;
		glVertex3f(x, y, ARENA_Z);
	}
	glEnd();

}

//Entities
int NextFreeSlot() {
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if (slots[i] == 0) {
			slots[i] = 1;
			return i;
		}
	}
	return MAX_ENTITIES;
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
	level++;
	level_isEmpty = 0;

	int random, i, njarras;
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
	//Desta forma é mais raro spawnar 2jarras ao mesmo tempo e ainda mais raro 3jarras
	random = rand() % 100;
	if (random < 5 || random > 94) njarras = 3;
	else if (random < 15 || random > 79) njarras = 2;
	else njarras = 1;
	for (i = 0; i < njarras; i++) {
		Spawn(Jar(RandomPosition()));
	}

	//Obstaculos
	random = rand() % (int)(map_radius / 10);
	for (i = 0; i <= random; i++) {
		Spawn(Block(RandomPosition()));
	}
}
int BestScore() {
	if (level > best_score)
		best_score = level;
	return best_score;
}
int restart() {
	for (int i = 0; i < MAX_ENTITIES; i++) slots[i] = 0;
	Spawn(Player());
	map_radius = 70;

	level = 0;
	level_isEmpty = 1;
	isLost = 0;

	return 1;
}



// Called to draw scene
void RenderScene(void) {
	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Draw 
	Draw_TorreFundo(25, -155, 100, 55);
	Draw_TorreFundo(20, -105, 75, 25);
	Draw_TorreFundo(20, -90, 45, 5);
	Draw_TorreFundo(15, -25, 115, 40);
	Draw_TorreFundo(32, -35, 55, -10);
	Draw_TorreFundo(20, 115, 95, 50);
	Draw_TorreFundo(25, 45, 85, 40);
	Draw_TorreFundo(25, 115, 30, -10);
	Draw_TorreFundo(45, 75, 15, -25);
	Draw_TorreFundo(20, -145, 15, -10);
	Draw_TorreFundo(20, 170, 60, 30);

	Map_Draw();
	// Entities
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if (slots[i]) {
			Draw(&entities[i]);
		}
	}


	//Draw current level score
	char slevel[20];
	char scoreString[20] = "Nivel: ";
	itoa(level, slevel, 10);
	strcat(scoreString, slevel);
	write(300, 300, -115, 85, GLUT_BITMAP_HELVETICA_18, scoreString);

	//Draw Best score
	char sscore[30];
	char bestScoreString[30] = "Melhor Pontuacao: ";
	itoa(BestScore(), sscore, 10);
	strcat(bestScoreString, sscore);
	write(300, 300, -115, 95, GLUT_BITMAP_HELVETICA_18, bestScoreString);

	//Draw when lost
	if (isLost) {
		write(300, 300, -15, 105, GLUT_BITMAP_HELVETICA_18, "PERDEU!");
	}
	if (!running) {
		write(300, 300, -17, -2, GLUT_BITMAP_HELVETICA_18, "PAUSA - [P]");
		glBegin(GL_POLYGON);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-windowWidth / 10, -windowHeight / 40, .1f);
		glVertex3f(-windowWidth / 10, windowHeight / 40, .1f);
		glVertex3f(windowWidth / 10, windowHeight / 40, .1f);
		glVertex3f(windowWidth / 10, -windowHeight / 40, .1f);
		glEnd();
	}
	if (finst) {
		write(300, 300, -35, 10, GLUT_BITMAP_HELVETICA_18, "MENU - [RATO DIREITO]");
		glBegin(GL_POLYGON);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-windowWidth / 5, -windowHeight / 40 + 12, .1f);
		glVertex3f(-windowWidth / 5, windowHeight / 40 + 12, .1f);
		glVertex3f(windowWidth / 5, windowHeight / 40 + 12, .1f);
		glVertex3f(windowWidth / 5, -windowHeight / 40 + 12, .1f);
		glEnd();
	}


	// Flush drawing commands
	glutSwapBuffers();
}

// Called by GLUT library when idle (window not being resized or moved)
void TimerFunction(int value) {
	if (running) {

		//Colisao & Movimento & AI & Outros
		for (int i1 = 0; i1 < MAX_ENTITIES; i1++) {
			if (slots[i1]) {
				struct Entity* entity1 = &entities[i1];

				//Caiu do mapa?
				if (Distance(&entity1->position, &vector_origin) > map_radius) {
					if (entity1->kind != 8) {
						Despawn(entity1->slot, 1);
						if (entity1->kind == 0) {
							isLost = 1;
							level_frame = 60;
						}
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
							Spawn(Particle(entity1->position, 0, 3));
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

					//Ataque
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
										Spawn(Particle(entity1->position, 0, 3));
										entity1->health--;
										if (entity1->health <= 0) {
											Despawn(entity1->slot, 1);
											Spawn(Particle(entity1->position, 1, 60));
										}
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
									Spawn(Particle(entity1->position, 5, 3));
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
						if (entity1->frame[1] == 0) {
							//Passa para a proxima faze da rotina
							entity1->frame[0]++;

							//Adiciona um salto ou reseta
							entity1->frame_imunity++;
							if (entity1->frame_imunity == 3) entity1->frame_imunity = 0;

							//Se ja for o 3o salto espera 60 frames, se nao apenas 10
							if (entity1->frame_imunity == 0) entity1->frame[1] = 60;
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
									Spawn(Particle(entity1->position, 0, 3));
									Despawn(entity1->slot, 1);
									Spawn(Particle(entity1->position, 2, 60));
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
										Spawn(Particle(entity1->position, 0, 3));
										entity1->health--;
										if (entity1->health <= 0) {
											Despawn(entity1->slot, 1);
											Spawn(Particle(entity1->position, 3, 60));
										}
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
					else if (entity1->health == 0) {
						Map_Increase();
						Despawn(entity1->slot, 0);
					}
				} break; //PickUp

				case 6: {
					if (entity1->health == 0) {
						Spawn(PickUp(entity1->position));
						Despawn(entity1->slot, 0);
						Spawn(Particle(entity1->position, 4, 60));
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
					if (entity1->frame_imunity == 0) {
						Despawn(entity1->slot, 0);
					}
				} break; //Particle
				}
			}
		}

		//Intervalo entre niveis ou Intervalo depois de perder
		if (level_isEmpty || isLost) {
			level_frame--;
			if (level_frame == 0) {
				level_frame = 60;

				if (isLost) restart();
				else LevelUp();
			}
		}

		//control time
		count_timer++;

		// Redraw the scene with new coordinates
		glutPostRedisplay();
	}

	glutTimerFunc(30, TimerFunction, 1);
}



void SpecialKeys(int key, int x, int y) {
	if (key == GLUT_KEY_UP) {
		PLAYER.direction.x = 0;
		PLAYER.direction.y = 1.0f;
		PLAYER.speed += 1;
	}

	if (key == GLUT_KEY_DOWN) {
		PLAYER.direction.x = 0;
		PLAYER.direction.y = -1.0f;
		PLAYER.speed += 1;
	}

	if (key == GLUT_KEY_LEFT) {
		PLAYER.direction.x = -1.0f;
		PLAYER.direction.y = 0;
		PLAYER.speed += 1;
	}

	if (key == GLUT_KEY_RIGHT) {
		PLAYER.direction.x = 1.0f;
		PLAYER.direction.y = 0;
		PLAYER.speed += 1;
	}

	glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27: exit(0); break;
	case '1': Map_Decrease(); break;
	case '2': Map_Increase(); break;
	case 'F': case 'f': {
		if (fullScreen) {
			glutPositionWindow(25, 25);
			glutReshapeWindow(1080, 600);
			fullScreen = 0;
		}
		else {
			glutFullScreen();
			fullScreen = 1;
		}
	} break;
	case 'P': case 'p': {
		if (running) running = 0;
		else {
			running = 1;
			finst = 0;
		}
	} break;
	case 'R': case 'r': restart();  break;
	}

	if (running && PLAYER.frame[0] == 0){
		switch (key) {
		case 'W': case 'w': SpecialKeys(GLUT_KEY_UP , 0, 0); break;
		case 'S': case 's': SpecialKeys(GLUT_KEY_DOWN, 0, 0); break;
		case 'D': case 'd': SpecialKeys(GLUT_KEY_RIGHT, 0, 0); break;
		case 'A': case 'a': SpecialKeys(GLUT_KEY_LEFT, 0, 0); break;
		case 'C': case 'c': {
			Spawn(PlayerSword(PLAYER));
			PLAYER.frame[0] = 4;
			PLAYER.speed += 1;
		} break;
		default: break;
		}
	}

	glutPostRedisplay();
}
void main_menu(int option) {
	switch (option) {
	case 1: restart(); break;
	case 2: exit(1); break;
	case 3: keyboard('f', 0, 0); break;
	case 4: keyboard('p',0,0); break;
	default: break;
	}
	glutPostRedisplay();
}
void create_menus() {
	int controls_menu = glutCreateMenu(main_menu);
	glutAddMenuEntry("W - Cima", 0);
	glutAddMenuEntry("S - Baixo", 0);
	glutAddMenuEntry("A - Esquerda", 0);
	glutAddMenuEntry("D - Direita", 0);
	glutAddMenuEntry("C - Ataque", 0);
	glutAddMenuEntry("R - Reiniciar", 0);
	glutAddMenuEntry("P - Pausa", 0);
	glutAddMenuEntry("F - Janela/Fullscren", 0); //
	glutAddMenuEntry("ESQ - Sair", 0);

	int instructions_menu = glutCreateMenu(main_menu);
	glutAddMenuEntry("-Mate todos os inimigos para subir de nivel.\n", 0);
	glutAddMenuEntry("-Se for atacado a arena reduz.\n", 0);
	glutAddMenuEntry("-Parta jarras para encontrar coracoes.\n", 0);
	glutAddMenuEntry("-Apanhe coracoes para aumentar a arena.\n", 0);
	glutAddMenuEntry("-Caia para perder com sucesso!\n", 0);

	int credits_menu = glutCreateMenu(main_menu);
	glutAddMenuEntry("a36741 Felix Silva", 0);
	glutAddMenuEntry("a42607 Hugo Brites", 0);
	glutAddMenuEntry("a37540 Isaias Silva", 0);
	glutAddMenuEntry("a41726 Ricardo Vieira", 0);

	int main_menu_id = glutCreateMenu(main_menu);
	glutAddSubMenu("CONTROLOS", controls_menu);
	glutAddSubMenu("INSTRUCOES", instructions_menu);
	glutAddSubMenu("CREDITOS", credits_menu);
	glutAddMenuEntry("JANELA/FULLSCREEN", 3);
	glutAddMenuEntry("PAUSA",4);
	glutAddMenuEntry("REINICIAR", 1);
	glutAddMenuEntry("SAIR", 2);

	glutAttachMenu(GLUT_RIGHT_BUTTON);

}



// Setup the rendering state
void SetupRC(void) {
	// Set clear color to blue
	glClearColor(BACKGROUND_COLOR, 1.0f);

	glEnable(GL_DEPTH_TEST);   // Enables depth-buffer for hidden surface removal
	glDepthFunc(GL_LEQUAL);    // The type of depth testing to do
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
	glOrtho(-windowWidth / 2, windowWidth / 2, -windowHeight / 2, windowHeight / 2, 1.0f, -250.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}



// Main program entry point
int main(int argc, char** argv) {
	glutInit(&argc, argv);      // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	//glutInitWindowSize(800, 720);
	//glutInitWindowPosition(25, 25);
	glutCreateWindow("EchoLands");
	glutFullScreen();

	vector_origin.x = 0;
	vector_origin.y = 0;

	Spawn(Player());

	create_menus();

	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(SpecialKeys);
	glutTimerFunc(30, TimerFunction, 1);

	SetupRC();
	glutMainLoop();
}
