#include "Player.h"
#include <gl/glut.h>
#include <math.h>

#include <iostream>
using namespace std;

Player::Player(float x, float y) {
	spawn(this);
	kind = 1;
	posX = x;
	posY = y;
	box = 5;
	speed = 2;
}
Player::~Player() {
	despawn(slot);
}

void Player::draw() {
	/// <summary>
	/// TEMPORARIO
	/// </summary>
	glColor3f(0.1f, 0.1f, 0.8f);
	glBegin(GL_TRIANGLE_FAN);
	for (float angle = 0.0f; angle < 2 * 3.14159; angle += 0.1) {
		float x = posX + sin(angle) * box;
		float y = posY + cos(angle) * box;
		glVertex2f(x, y);
	}
	glEnd();
}

void Player::die() {
	this->~Player();
}

void Player::reactToEntity(Entity* entity) {
	switch (entity->kind) {
	case 2:
		MAP->DecreaseMap();
		break;
	case 3:
		break;
	default:
		break;
	}
}
