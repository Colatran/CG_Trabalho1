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
	glVertex2f(-10, 70);
	glVertex2f(10, 70);
	glVertex2f(10, 50);
	glVertex2f(-10, 50);
	glEnd();
	//ORELHAS
	glColor3f(0.8, 0.4, 0);
	glBegin(GL_POLYGON);
	glVertex2f(10, 65);
	glVertex2f(30, 75);
	glVertex2f(10, 55);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-10, 65);
	glVertex2f(-30, 75);
	glVertex2f(-10, 55);
	glEnd();
	//CABELO
	glColor3f(0.2, 0.4, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-10, 65);
	glVertex2f(-12, 72);
	glVertex2f(-10, 85);
	glVertex2f(0, 70);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(10, 85);
	glVertex2f(12, 72);
	glVertex2f(10, 65);
	glVertex2f(0, 70);
	glEnd();
	glColor3f(0.3, 0.6, 0);
	glBegin(GL_POLYGON);
	glVertex2f(0, 65);
	glVertex2f(-10, 75);
	glVertex2f(0, 90);
	glVertex2f(10, 75);
	glEnd();
	//OLHOS
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(-7.5, 55);
	glVertex2f(-2.5, 55);
	glVertex2f(-2.5, 60);
	glVertex2f(-7.5, 60);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(7.5, 55);
	glVertex2f(2.5, 55);
	glVertex2f(2.5, 60);
	glVertex2f(7.5, 60);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-2.5, 55);
	glVertex2f(-5, 55);
	glVertex2f(-5, 57.5);
	glVertex2f(-2.5, 57.5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(2.5, 55);
	glVertex2f(5, 55);
	glVertex2f(5, 57.5);
	glVertex2f(2.5, 57.5);
	glEnd();
	glColor3f(0.2, 0.4, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-2.5, 57.5);
	glVertex2f(-5, 57.5);
	glVertex2f(-5, 60);
	glVertex2f(-2.5, 60);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(2.5, 57.5);
	glVertex2f(5, 57.5);
	glVertex2f(5, 60);
	glVertex2f(2.5, 60);
	glEnd();


	//TORSO
	glColor3f(0, 0.3, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(-10, 50);
	glVertex2f(10, 50);
	glVertex2f(10, 30);
	glVertex2f(0, 20);
	glVertex2f(-10, 30);
	glEnd();
	glColor3f(0, 0.09, 0.2);
	glBegin(GL_LINES);
	glVertex2f(0, 50);
	glVertex2f(0, 20);
	glEnd();
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(2.5, 40);
	glVertex2f(5, 40);
	glVertex2f(5, 36.5);
	glVertex2f(2.5, 36.5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(2.5, 34);
	glVertex2f(5, 34);
	glVertex2f(5, 30.5);
	glVertex2f(2.5, 30.5);
	glEnd();
	//Pescoço
	glColor3f(0, 0.09, 0.2);
	glBegin(GL_POLYGON);
	glVertex2f(-10, 50);
	glVertex2f(10, 50);
	glVertex2f(0, 40);
	glEnd();
	glColor3f(0.8, 0.4, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-5, 50);
	glVertex2f(5, 50);
	glVertex2f(0, 45);
	glEnd();

	//BRAÇO_ESQ
	glColor3f(1, 0.7, 0.4);
	glBegin(GL_POLYGON);
	glVertex2f(-17.5, 50);
	glVertex2f(-12.5, 50);
	glVertex2f(-12.5, 30);
	glVertex2f(-17.5, 30);
	glEnd();
	glColor3f(0.8, 0.4, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-17.5, 50);
	glVertex2f(-12.5, 50);
	glVertex2f(-12.5, 40);
	glVertex2f(-17.5, 45);
	glEnd();
	glColor3f(0, 0.3, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(-20, 50);
	glVertex2f(-10, 50);
	glVertex2f(-10, 40);
	glEnd();
	glColor3f(0.7, 0.7, 0.7);
	glBegin(GL_POLYGON);
	glVertex2f(-17.5, 35);
	glVertex2f(-12.5, 35);
	glVertex2f(-17.5, 30);
	glEnd();
	glColor3f(0.8, 0.4, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-17.5, 35);
	glVertex2f(-12.5, 35);
	glVertex2f(-12.5, 37);
	glVertex2f(-17.5, 37);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-12.5, 35);
	glVertex2f(-12.5, 33);
	glVertex2f(-15.5, 30);
	glVertex2f(-17.5, 30);
	glEnd();
	//BRAÇO_DIR
	glColor3f(1, 0.7, 0.4);
	glBegin(GL_POLYGON);
	glVertex2f(17.5, 50);
	glVertex2f(12.5, 50);
	glVertex2f(12.5, 30);
	glVertex2f(17.5, 30);
	glEnd();
	glColor3f(0.8, 0.4, 0);
	glBegin(GL_POLYGON);
	glVertex2f(17.5, 50);
	glVertex2f(12.5, 50);
	glVertex2f(12.5, 40);
	glVertex2f(17.5, 45);
	glEnd();
	glColor3f(0, 0.3, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(20, 50);
	glVertex2f(10, 50);
	glVertex2f(10, 40);
	glEnd();
	glColor3f(0.7, 0.7, 0.7);
	glBegin(GL_POLYGON);
	glVertex2f(17.5, 35);
	glVertex2f(12.5, 35);
	glVertex2f(17.5, 30);
	glEnd();
	glColor3f(0.8, 0.4, 0);
	glBegin(GL_POLYGON);
	glVertex2f(17.5, 35);
	glVertex2f(12.5, 35);
	glVertex2f(12.5, 37);
	glVertex2f(17.5, 37);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(12.5, 35);
	glVertex2f(12.5, 33);
	glVertex2f(15.5, 30);
	glVertex2f(17.5, 30);
	glEnd();

	//PERNA_ESQ
	glColor3f(0.7, 0.7, 0.7);
	glBegin(GL_POLYGON);
	glVertex2f(-10, 30);
	glVertex2f(0, 20);
	glVertex2f(-10, 0);
	glVertex2f(-12, 20);
	glEnd();
	//PERNA_DIR
	glColor3f(0.7, 0.7, 0.7);
	glBegin(GL_POLYGON);
	glVertex2f(10, 30);
	glVertex2f(0, 20);
	glVertex2f(10, 0);
	glVertex2f(12, 20);
	glEnd();

	//PE_ESQ
	glColor3f(0.2, 0.09, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-10, 0);
	glVertex2f(-15, 10);
	glVertex2f(-5, 8);
	glEnd();
	glColor3f(0.4, 0.2, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-10, 8);
	glVertex2f(-5, 0);
	glVertex2f(-20, 0);
	glEnd();
	//PE_DIR
	glColor3f(0.2, 0.09, 0);
	glBegin(GL_POLYGON);
	glVertex2f(10, 0);
	glVertex2f(15, 10);
	glVertex2f(5, 8);
	glEnd();
	glColor3f(0.4, 0.2, 0);
	glBegin(GL_POLYGON);
	glVertex2f(10, 8);
	glVertex2f(5, 0);
	glVertex2f(20, 0);
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
	case 5: //PickUp
		draw_pickup(entity->position);
		break;
	case 7: //Block
		draw_block(entity->position);
		break;//
	}
}