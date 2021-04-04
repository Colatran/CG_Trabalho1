#include "Pickup.h"

#include <iostream>
using namespace std;

Pickup::Pickup(Vector location) {
	spawn(this);
	position = Vector(location.x + ORIGIN, location.y + ORIGIN);
	kind = 3;
	box = 10;
}
Pickup::~Pickup() {
	despawn(slot);
}

void Pickup::draw() {
	/// <summary>
	/// TEMPORARIO
	/// </summary>
	glColor3f(0.8f, 0.3f, 0.3f);
	glBegin(GL_TRIANGLE_FAN);
	for (float angle = 0.0f; angle < 2 * 3.14159; angle += 0.1) {
		float x = position.x + sin(angle) * box/2;
		float y = position.y + cos(angle) * box/2;
		glVertex2f(x, y);
	}
	glEnd();
}

void Pickup::die() {
	this->~Pickup();
}

