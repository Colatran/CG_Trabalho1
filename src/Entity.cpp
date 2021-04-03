#include "Entity.h"
#include <gl/glut.h>
#include <math.h>

Entity* Entity::entities[50];
bool Entity::slots[50] = {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0};

void Entity::draw() {
	/*glColor3f(0.8f, 0.1f, 0.1f);
	glBegin(GL_TRIANGLE_FAN);
	for (float angle = 0.0f; angle < 2 * 3.14159; angle += 0.1) {
		float x = posX + sin(angle) * 10;
		float y = posY + cos(angle) * 10;
		glVertex2f(x, y);
	}
	glEnd();*/
}
void Entity::die() {}
void Entity::reactToEntity(Entity* entity) {}

void Entity::move() {
	posX += dirX*speed;
	posY += dirY*speed;
}
void Entity::collision() {
	// With the map
	if (distanceTo(ORIGIN, ORIGIN) > MAP->radius) die();

	// With other entities
	for (int i = 0; i < 50; i++) {
		if (slots[i]) {
			Entity *entity = entities[i];
			if (distanceTo(entity->posX, entity->posY) < entity->box) reactToEntity(entity);
		}
	}
}
float Entity::distanceTo(float x, float y) {
	return sqrt(((posX - x) * (posX - x)) + ((posY - y) * (posY - y)));
}

void Entity::spawn(Entity* entity) {
	entity->slot = nextFreeSlot();
	entities[entity->slot] = entity;
}
void Entity::despawn(int index) {
	slots[index] = false;
}
int Entity::nextFreeSlot() {
	for (int i = 0; i < 100; i++) {
		if (!slots[i]) {
			slots[i] = true;
			return i;
		}
	}
	return 100;
}