#include "Map.h"
#include <gl/glut.h>
#include <math.h>

#include <iostream>
using namespace std;

Map* Map::ref;

Map::Map(){}

void Map::draw() {
	glColor3f(0.8f, 0.8f, 0.1f);
	glBegin(GL_TRIANGLE_FAN);
	for (float angle = 0.0f; angle < 2 * 3.14159; angle += 0.1) {
		float x = ORIGIN + sin(angle) * radius;
		float y = ORIGIN + cos(angle) * radius;
		glVertex2f(x, y);
	}
	glEnd();
}
void Map::DecreaseMap() { if (radius > 0) radius -= 5.0f; }
void Map::IncreaseMap() { if (radius < 120) radius += 5.0f; }

float Map::RandomFloat(float min, float max) {
	float random = ((float)rand()) / (float)RAND_MAX;
	float range = max - min;
	return (random * range) + min;
}
Vector Map::RandomPosition() {
	float angle = RandomFloat(0, 360);
	float length = RandomFloat(0, ref->radius);
	return Vector(sin(angle) * length, cos(angle) * length);
}
