#include "Entity.h"

Entity* Entity::entities[50];

bool Entity::slots[50] = { 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 };

void Entity::draw() {}
void Entity::move() {}
void Entity::die() {}
void Entity::reactToEntity(Entity* entity) {}

void Entity::collision() {
	// With the map
	if (distanceTo(Vector::origin) + box > MAP->radius) die();

	// With other entities
	for (int i = 0; i < 50; i++) {
		if (i == slot) {}
		else if (slots[i]) {
			Entity* entity = entities[i];
			if (distanceTo(entity->position) < entity->box) reactToEntity(entity);
		}
	}
}
float Entity::distanceTo(Vector point) {
	return sqrt(((position.x - point.x) * (position.x - point.x)) + ((position.y - point.y) * (position.y - point.y)));
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