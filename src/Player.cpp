#include "Player.h"

Player::Player(Vector location) {
	spawn(this);
	position = Vector(location.x + ORIGIN, location.y + ORIGIN);
	velocity = Vector::zero;

	kind = 1;
	box = 10;
}
Player::~Player() {
	despawn(slot);
}

void Player::draw() {
	/// <summary>
	/// TEMPORARIO
	/// Depois temos de fazer os desenhos dos personagens
	/// </summary>
	glColor3f(0.1f, 0.1f, 0.8f);
	glBegin(GL_TRIANGLE_FAN);
	for (float angle = 0.0f; angle < 2 * 3.14159; angle += 0.1) {
		float x = position.x + sin(angle) * box/2;
		float y = position.y + cos(angle) * box/2;
		glVertex2f(x, y);
	}
	glEnd();
}

void Player::move() {
	position.x += velocity.x * speed;
	position.y += velocity.y * speed;
	velocity = Vector::zero;
}

void Player::die() {
	this->~Player();
}

void Player::reactToEntity(Entity* entity) {
	switch (entity->kind) {
	case -2:
		MAP->DecreaseMap();
		break;
	case 3:
		MAP->IncreaseMap();
		entity->die();
		break;
	default:
		break;
	}
}
