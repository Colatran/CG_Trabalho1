#pragma once
#include <gl/glut.h>
#include <math.h>
#include "Entity.h"

void draw_circle(struct Vector position, GLfloat r, GLfloat g, GLfloat b) {
	glColor3f(r, g, b);
	glBegin(GL_TRIANGLE_FAN);
	for (float angle = 0.0f; angle < 2 * 3.14159; angle += 0.1) {
		float x = position.x + sin(angle) * 5;
		float y = position.y + cos(angle) * 5;
		glVertex2f(x, y);
	}
	glEnd();
}

/// <summary>
/// TEMPORARIO /// TEMPORARIO /// TEMPORARIO /// TEMPORARIO
/// Depois temos de fazer os desenhos dos personagens
/// TEMPORARIO /// TEMPORARIO /// TEMPORARIO /// TEMPORARIO
/// </summary>
void draw_player(struct Vector position) {
	draw_circle(position, 0.1f, 0.1f, 0.8f);
}

void draw_pickup(struct Vector position) {
	draw_circle(position, 0.8f, 0.3f, 0.3f);
}


void Draw(struct Entity *entity) {
	switch (entity->kind) {
	case 0: //Palyer
		draw_player(entity->position);
		break;
	case 1: //PickUp
		draw_pickup(entity->position);
		break;
	}
}