#pragma once
#include <gl/glut.h>
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
void draw_square(struct Vector position, GLfloat r, GLfloat g, GLfloat b) {
	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2f(position.x - 5, position.y - 5);
	glVertex2f(position.x + 5, position.y - 5);
	glVertex2f(position.x + 5, position.y + 5);
	glVertex2f(position.x - 5, position.y + 5);
	glEnd();
}


void draw_player(struct Vector position) {

	//CABEÇA
	glColor3f(1, 0.7, 0.4);
	glBegin(GL_POLYGON);
	glVertex2f(position.x - 10, position.y + 70);
	glVertex2f(position.x + 10, position.y + 70);
	glVertex2f(position.x + 10, position.y + 50);
	glVertex2f(position.x - 10, position.y + 50);
	glEnd();
	//ORELHAS
	glColor3f(0.8, 0.4, 0);
	glBegin(GL_POLYGON);
	glVertex2f(position.x + 10, position.y + 65);
	glVertex2f(position.x + 30, position.y + 75);
	glVertex2f(position.x + 10, position.y + 55);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(position.x - 10, position.y + 65);
	glVertex2f(position.x - 30, position.y + 75);
	glVertex2f(position.x - 10, position.y + 55);
	glEnd();
	//CABELO
	glColor3f(0.2, 0.4, 0);
	glBegin(GL_POLYGON);
	glVertex2f(position.x - 10, position.y + 65);
	glVertex2f(position.x - 12, position.y + 72);
	glVertex2f(position.x - 10, position.y + 85);
	glVertex2f(position.x + 0, position.y + 70);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(position.x + 10, position.y + 85);
	glVertex2f(position.x + 12, position.y + 72);
	glVertex2f(position.x + 10, position.y + 65);
	glVertex2f(position.x + 0, position.y + 70);
	glEnd();
	glColor3f(0.3, 0.6, 0);
	glBegin(GL_POLYGON);
	glVertex2f(position.x + 0, position.y + 65);
	glVertex2f(position.x - 10, position.y + 75);
	glVertex2f(position.x + 0, position.y + 90);
	glVertex2f(position.x + 10, position.y + 75);
	glEnd();
	//OLHOS
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(position.x - 7.5, position.y + 55);
	glVertex2f(position.x - 2.5, position.y + 55);
	glVertex2f(position.x - 2.5, position.y + 60);
	glVertex2f(position.x - 7.5, position.y + 60);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(position.x + 7.5, position.y + 55);
	glVertex2f(position.x + 2.5, position.y + 55);
	glVertex2f(position.x + 2.5, position.y + 60);
	glVertex2f(position.x + 7.5, position.y + 60);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(position.x - 2.5, position.y + 55);
	glVertex2f(position.x - 5, position.y + 55);
	glVertex2f(position.x - 5, position.y + 57.5);
	glVertex2f(position.x - 2.5, position.y + 57.5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(position.x + 2.5, position.y + 55);
	glVertex2f(position.x + 5, position.y + 55);
	glVertex2f(position.x + 5, position.y + 57.5);
	glVertex2f(position.x + 2.5, position.y + 57.5);
	glEnd();
	glColor3f(0.2, 0.4, 0);
	glBegin(GL_POLYGON);
	glVertex2f(position.x - 2.5, position.y + 57.5);
	glVertex2f(position.x - 5, position.y + 57.5);
	glVertex2f(position.x - 5, position.y + 60);
	glVertex2f(position.x - 2.5, position.y + 60);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(position.x + 2.5, position.y + 57.5);
	glVertex2f(position.x + 5, position.y + 57.5);
	glVertex2f(position.x + 5, position.y + 60);
	glVertex2f(position.x + 2.5, position.y + 60);
	glEnd();

	//TORSO
	glColor3f(0, 0.3, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(position.x - 10, position.y + 50);
	glVertex2f(position.x + 10, position.y + 50);
	glVertex2f(position.x + 10, position.y + 30);
	glVertex2f(position.x + 0, position.y + 20);
	glVertex2f(position.x - 10, position.y + 30);
	glEnd();
	glColor3f(0, 0.09, 0.2);
	glBegin(GL_LINES);
	glVertex2f(position.x + 0, position.y + 50);
	glVertex2f(position.x + 0, position.y + 20);
	glEnd();
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(position.x + 2.5, position.y + 40);
	glVertex2f(position.x + 5, position.y + 40);
	glVertex2f(position.x + 5, position.y + 36.5);
	glVertex2f(position.x + 2.5, position.y + 36.5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(position.x + 2.5, position.y + 34);
	glVertex2f(position.x + 5, position.y + 34);
	glVertex2f(position.x + 5, position.y + 30.5);
	glVertex2f(position.x + 2.5, position.y + 30.5);
	glEnd();
	//Pescoço
	glColor3f(0, 0.09, 0.2);
	glBegin(GL_POLYGON);
	glVertex2f(position.x - 10, position.y + 50);
	glVertex2f(position.x + 10, position.y + 50);
	glVertex2f(position.x + 0, position.y + 40);
	glEnd();
	glColor3f(0.8, 0.4, 0);
	glBegin(GL_POLYGON);
	glVertex2f(position.x - 5, position.y + 50);
	glVertex2f(position.x + 5, position.y + 50);
	glVertex2f(position.x + 0, position.y + 45);
	glEnd();

	//BRAÇO_ESQ
	glColor3f(1, 0.7, 0.4);
	glBegin(GL_POLYGON);
	glVertex2f(position.x - 17.5, position.y + 50);
	glVertex2f(position.x - 12.5, position.y + 50);
	glVertex2f(position.x - 12.5, position.y + 30);
	glVertex2f(position.x - 17.5, position.y + 30);
	glEnd();
	glColor3f(0.8, 0.4, 0);
	glBegin(GL_POLYGON);
	glVertex2f(position.x - 17.5, position.y + 50);
	glVertex2f(position.x - 12.5, position.y + 50);
	glVertex2f(position.x - 12.5, position.y + 40);
	glVertex2f(position.x - 17.5, position.y + 45);
	glEnd();
	glColor3f(0, 0.3, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(position.x - 20, position.y + 50);
	glVertex2f(position.x - 10, position.y + 50);
	glVertex2f(position.x - 10, position.y + 40);
	glEnd();
	glColor3f(0.7, 0.7, 0.7);
	glBegin(GL_POLYGON);
	glVertex2f(position.x - 17.5, position.y + 35);
	glVertex2f(position.x - 12.5, position.y + 35);
	glVertex2f(position.x - 17.5, position.y + 30);
	glEnd();
	glColor3f(0.8, 0.4, 0);
	glBegin(GL_POLYGON);
	glVertex2f(position.x - 17.5, position.y + 35);
	glVertex2f(position.x - 12.5, position.y + 35);
	glVertex2f(position.x - 12.5, position.y + 37);
	glVertex2f(position.x - 17.5, position.y + 37);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(position.x - 12.5, position.y + 35);
	glVertex2f(position.x - 12.5, position.y + 33);
	glVertex2f(position.x - 15.5, position.y + 30);
	glVertex2f(position.x - 17.5, position.y + 30);
	glEnd();
	//BRAÇO_DIR
	glColor3f(1, 0.7, 0.4);
	glBegin(GL_POLYGON);
	glVertex2f(position.x + 17.5, position.y + 50);
	glVertex2f(position.x + 12.5, position.y + 50);
	glVertex2f(position.x + 12.5, position.y + 30);
	glVertex2f(position.x + 17.5, position.y + 30);
	glEnd();
	glColor3f(0.8, 0.4, 0);
	glBegin(GL_POLYGON);
	glVertex2f(position.x + 17.5, position.y + 50);
	glVertex2f(position.x + 12.5, position.y + 50);
	glVertex2f(position.x + 12.5, position.y + 40);
	glVertex2f(position.x + 17.5, position.y + 45);
	glEnd();
	glColor3f(0, 0.3, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(position.x + 20, position.y + 50);
	glVertex2f(position.x + 10, position.y + 50);
	glVertex2f(position.x + 10, position.y + 40);
	glEnd();
	glColor3f(0.7, 0.7, 0.7);
	glBegin(GL_POLYGON);
	glVertex2f(position.x + 17.5, position.y + 35);
	glVertex2f(position.x + 12.5, position.y + 35);
	glVertex2f(position.x + 17.5, position.y + 30);
	glEnd();
	glColor3f(0.8, 0.4, 0);
	glBegin(GL_POLYGON);
	glVertex2f(position.x + 17.5, position.y + 35);
	glVertex2f(position.x + 12.5, position.y + 35);
	glVertex2f(position.x + 12.5, position.y + 37);
	glVertex2f(position.x + 17.5, position.y + 37);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(position.x + 12.5, position.y + 35);
	glVertex2f(position.x + 12.5, position.y + 33);
	glVertex2f(position.x + 15.5, position.y + 30);
	glVertex2f(position.x + 17.5, position.y + 30);
	glEnd();

	//PERNA_ESQ
	glColor3f(0.7, 0.7, 0.7);
	glBegin(GL_POLYGON);
	glVertex2f(position.x - 10, position.y + 30);
	glVertex2f(position.x + 0, position.y + 20);
	glVertex2f(position.x - 10, position.y + 0);
	glVertex2f(position.x - 12, position.y + 20);
	glEnd();
	//PERNA_DIR
	glColor3f(0.7, 0.7, 0.7);
	glBegin(GL_POLYGON);
	glVertex2f(position.x + 10, position.y + 30);
	glVertex2f(position.x + 0, position.y + 20);
	glVertex2f(position.x + 10, position.y + 0);
	glVertex2f(position.x + 12, position.y + 20);
	glEnd();

	//PE_ESQ
	glColor3f(0.2, 0.09, 0);
	glBegin(GL_POLYGON);
	glVertex2f(position.x - 10, position.y + 0);
	glVertex2f(position.x - 15, position.y + 10);
	glVertex2f(position.x - 5, position.y + 8);
	glEnd();
	glColor3f(0.4, 0.2, 0);
	glBegin(GL_POLYGON);
	glVertex2f(position.x - 10, position.y + 8);
	glVertex2f(position.x - 5, position.y + 0);
	glVertex2f(position.x - 20, position.y + 0);
	glEnd();
	//PE_DIR
	glColor3f(0.2, 0.09, 0);
	glBegin(GL_POLYGON);
	glVertex2f(position.x + 10, position.y + 0);
	glVertex2f(position.x + 15, position.y + 10);
	glVertex2f(position.x + 5, position.y + 8);
	glEnd();
	glColor3f(0.4, 0.2, 0);
	glBegin(GL_POLYGON);
	glVertex2f(position.x + 10, position.y + 8);
	glVertex2f(position.x + 5, position.y + 0);
	glVertex2f(position.x + 20, position.y + 0);
	glEnd();

}

void draw_pickup(struct Vector position) {
	draw_circle(position, 0.8f, 0.3f, 0.3f);
}

void draw_block(struct Vector position) {
	draw_circle(position, 0.2f, 0.1f, 0.1f);
}

void Draw(struct Entity* entity) {
	switch (entity->kind) {
	case 0: //Palyer
		draw_player(entity->position);
		break;
	case 1: //PickUp
		draw_pickup(entity->position);
		break;
	case 2: //Block
		draw_block(entity->position);
		break;//
	}
}