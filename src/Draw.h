#pragma once
#include <gl/glut.h>
#include "Entity.h"

void draw_circle(GLfloat r, GLfloat g, GLfloat b, float radius) {
	glColor3f(r, g, b);
	glBegin(GL_TRIANGLE_FAN);
	for (float angle = 0.0f; angle < 2 * 3.14159; angle += 0.1) {
		float x = sin(angle) * radius;
		float y = cos(angle) * radius;
		glVertex2f(x, y);
	}
	glEnd();
}



void draw_player() {
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	for (float angle = 0.0f; angle < 2 * 3.14159; angle += 0.1) {
		float x = sin(angle) * 15;
		float y = cos(angle) * 15;
		glVertex2f(x, y);
	}
	glEnd();

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

void draw_thrower() {
	draw_circle(0.0f, 0.0f, 0.0f, 5);
}

void draw_throwerProjectile() {
	draw_circle(0.0f, 0.0f, 0.0f, 5);
}

void draw_blobSmall() {
	draw_circle(0.0f, 0.0f, 0.0f, 5);
}

void draw_blobBig() {
	draw_circle(0.0f, 0.0f, 0.0f, 5);
}

void draw_pickup() {
	draw_circle(0.8f, 0.3f, 0.3f, 5);
}

void draw_jar() {
	draw_circle(0.2f, 0.1f, 0.1f, 5);
}

void draw_block() {
	draw_circle(0.0f, 0.0f, 0.0f, 5);
}

void draw_playerSword(struct Vector vector) {
	glColor3f(1.0, 1.0, 1.0);
	glRectf(-1, 0, 1, -20);
	glEnd();
}



void Draw(struct Entity* entity) {
	float angle;

	switch (entity->kind) {

	case 0: //Palyer
		glScalef(.3333f, .3333f, 1.0f);
		glTranslatef(entity->position.x * 3, entity->position.y * 3 -25, 0);
		draw_player();
		break;

	case 1: //Enemy Thrower
		glScalef(1.0f, 1.0f, 1.0f);
		glTranslatef(entity->position.x, entity->position.y, 0);
		draw_thrower();
		break;

	case 2: //Enemy Thrower Projectile
		glScalef(1.0f, 1.0f, 1.0f);
		glTranslatef(entity->position.x, entity->position.y, 0);
		draw_throwerProjectile();
		break;

	case 3: //Enemy Blob Small
		glScalef(1.0f, 1.0f, 1.0f);
		glTranslatef(entity->position.x, entity->position.y, 0);
		draw_blobSmall();
		break;

	case 4: //Enemy Blob Big
		glScalef(1.0f, 1.0f, 1.0f);
		glTranslatef(entity->position.x, entity->position.y, 0);
		draw_blobBig();
		break;

	case 5: //PickUp
		glScalef(1.0f, 1.0f, 1.0f);
		glTranslatef(entity->position.x, entity->position.y, 0);
		draw_pickup();
		break;

	case 6: //Jar
		glScalef(1.0f, 1.0f, 1.0f);
		glTranslatef(entity->position.x, entity->position.y, 0);
		draw_jar();
		break;

	case 7: //Block
		glScalef(1.0f, 1.0f, 1.0f);
		glTranslatef(entity->position.x, entity->position.y, 0);
		draw_block();
		break;

	case 8: //Palyer Sword
		if (entity->direction.x == 0) angle = asin(entity->direction.y);
		else angle = acos(entity->direction.x);
		angle = angle * 180 / 3.141593 + 67.5 + 45 * entity->frame / 3;

		glScalef(1.0f, 1.0f, 1.0f);
		glTranslatef(entity->position.x - entity->direction.x * 10, entity->position.y - entity->direction.y * 10, 0);
		glRotatef(angle, 0, 0, 1);
		draw_playerSword(entity->direction);
		break;
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}