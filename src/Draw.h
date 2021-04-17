#pragma once
#include <gl/glut.h>
#include "Entity.h"
#include <string.h>

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
	//SOMBRA
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	for (float angle = 0.0f; angle < 2 * 3.14159; angle += 0.1) {
		float x = sin(angle) * 20;
		float y = cos(angle) * 20;
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
	glColor3f(1, 1, 1);
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
	glColor3f(1, 1, 1);
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
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(-10, 30);
	glVertex2f(0, 20);
	glVertex2f(-10, 0);
	glVertex2f(-12, 20);
	glEnd();
	//PERNA_DIR
	glColor3f(1, 1, 1);
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
	//SOMBRA
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	for (float angle = 0.0f; angle < 2 * 3.14159; angle += 0.1) {
		float x = sin(angle) * 20;
		float y = cos(angle) * 20;
		glVertex2f(x, y);
	}
	glEnd();

	//BRAÇOS
	glColor3f(0, 0.2, 0.4);
	glBegin(GL_POLYGON);
	glVertex2f(20, 60);
	glVertex2f(30, 45);
	glVertex2f(20, 45);
	glVertex2f(10, 60);
	glEnd();
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(20, 45);
	glVertex2f(30, 45);
	glVertex2f(30, 30);
	glVertex2f(20, 30);
	glEnd();
	glColor3f(0, 0.2, 0.4);
	glBegin(GL_POLYGON);
	glVertex2f(-20, 60);
	glVertex2f(-30, 45);
	glVertex2f(-20, 45);
	glVertex2f(-10, 60);
	glEnd();
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(-20, 45);
	glVertex2f(-30, 45);
	glVertex2f(-30, 30);
	glVertex2f(-20, 30);
	glEnd();
	//OMBROS
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(-20, 52);
	glVertex2f(-20, 67);
	glVertex2f(-35, 67);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(20, 52);
	glVertex2f(20, 67);
	glVertex2f(35, 67);
	glEnd();

	//TORSO
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(-20, 70);
	glVertex2f(20, 70);
	glVertex2f(20, 50);
	glVertex2f(10, 40);
	glVertex2f(-10, 40);
	glVertex2f(-20, 50);
	glEnd();
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(-20, 50);
	glVertex2f(20, 50);
	glVertex2f(10, 40);
	glVertex2f(-10, 40);
	glEnd();
	//PEITOS
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(-10, 45);
	glVertex2f(0, 47.5);
	glVertex2f(0, 50);
	glVertex2f(-20, 50);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(10, 45);
	glVertex2f(0, 47.5);
	glVertex2f(0, 50);
	glVertex2f(20, 50);
	glEnd();
	//PELVIS
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(10, 40);
	glVertex2f(10, 25);
	glVertex2f(0, 20);
	glVertex2f(-10, 25);
	glVertex2f(-10, 40);
	glEnd();

	//PERNA_DIR
	glColor3f(0, 0.2, 0.4);
	glBegin(GL_POLYGON);
	glVertex2f(10, 30);
	glVertex2f(20, 20);
	glVertex2f(10, 20);
	glVertex2f(0, 30);
	glEnd();
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(10, 20);
	glVertex2f(20, 20);
	glVertex2f(20, 10);
	glVertex2f(10, 10);
	glEnd();
	//PE_DIR
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(10, 10);
	glVertex2f(30, 10);
	glVertex2f(30, 0);
	glVertex2f(10, 0);
	glEnd();

	//PERNA_ESQ
	glColor3f(0, 0.2, 0.4);
	glBegin(GL_POLYGON);
	glVertex2f(-10, 30);
	glVertex2f(-20, 20);
	glVertex2f(-10, 20);
	glVertex2f(0, 30);
	glEnd();
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(-10, 20);
	glVertex2f(-20, 20);
	glVertex2f(-20, 10);
	glVertex2f(-10, 10);
	glEnd();
	//PE_ESQ
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(-10, 10);
	glVertex2f(-30, 10);
	glVertex2f(-30, 0);
	glVertex2f(-10, 0);
	glEnd();

	//MAOs
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(-32.5, 32.5);
	glVertex2f(-17.5, 32.5);
	glVertex2f(-17.5, 17.5);
	glVertex2f(-32.5, 17.5);
	glEnd();
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(32.5, 32.5);
	glVertex2f(17.5, 32.5);
	glVertex2f(17.5, 17.5);
	glVertex2f(32.5, 17.5);
	glEnd();

	//CABEÇA
	glColor3f(0.75, 0.75, 0.75);
	glBegin(GL_POLYGON);
	glVertex2f(10, 80);
	glVertex2f(10, 55);
	glVertex2f(-10, 55);
	glVertex2f(-10, 80);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(5, 55);
	glVertex2f(5, 50);
	glVertex2f(-5, 50);
	glVertex2f(-5, 55);
	glEnd();

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(-1, 65);
	glVertex2f(-12, 65);
	glVertex2f(-10, 70);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(1, 65);
	glVertex2f(12, 65);
	glVertex2f(10, 70);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-7, 78);
	glVertex2f(7, 78);
	glVertex2f(7, 72);
	glVertex2f(0, 68);
	glVertex2f(-7, 72);
	glEnd();

	//OLHO_DIR
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(3, 60);
	glVertex2f(7, 60);
	glVertex2f(7, 65);
	glVertex2f(3, 65);
	glEnd();
	//OLHO_ESQ
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(-3, 60);
	glVertex2f(-7, 60);
	glVertex2f(-7, 65);
	glVertex2f(-3, 65);
	glEnd();

	//ROUPA
	glColor3f(0.4, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(10, 30);
	glVertex2f(2, 10);
	glVertex2f(-10, 30);
	glEnd();
	glColor3f(0.6, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(10, 30);
	glVertex2f(-2, 10);
	glVertex2f(-10, 30);
	glEnd();


}

void draw_skelet_gib(void) {
	//SOMBRA
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	for (float angle = 0.0f; angle < 2 * 3.14159; angle += 0.1) {
		float x = sin(angle) * 20;
		float y = cos(angle) * 20 + 20;
		glVertex2f(x, y);
	}
	glEnd();

	//OMBROS
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(-20, 15);
	glVertex2f(-35, 15);
	glVertex2f(-35, 30);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(20, 27);
	glVertex2f(20, 42);
	glVertex2f(35, 42);
	glEnd();

	//TORSO
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(-20, 45);
	glVertex2f(20, 45);
	glVertex2f(20, 25);
	glVertex2f(10, 15);
	glVertex2f(-10, 15);
	glVertex2f(-20, 25);
	glEnd();
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(-20, 25);
	glVertex2f(20, 25);
	glVertex2f(10, 15);
	glVertex2f(-10, 15);
	glEnd();
	//PEITOS
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(-10, 20);
	glVertex2f(0, 22.5);
	glVertex2f(0, 25);
	glVertex2f(-20, 25);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(10, 20);
	glVertex2f(0, 22.5);
	glVertex2f(0, 25);
	glVertex2f(20, 25);
	glEnd();

	//CABEÇA
	glColor3f(0.75, 0.75, 0.75);
	glBegin(GL_POLYGON);
	glVertex2f(10, 55);
	glVertex2f(10, 30);
	glVertex2f(-10, 30);
	glVertex2f(-10, 55);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(5, 30);
	glVertex2f(5, 25);
	glVertex2f(-5, 25);
	glVertex2f(-5, 30);
	glEnd();

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(-1, 40);
	glVertex2f(-12, 40);
	glVertex2f(-10, 45);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(1, 40);
	glVertex2f(12, 40);
	glVertex2f(10, 45);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-7, 53);
	glVertex2f(7, 53);
	glVertex2f(7, 47);
	glVertex2f(0, 43);
	glVertex2f(-7, 47);
	glVertex2f(-7, 53);
	glEnd();

}

void draw_throwerProjectile() {
	draw_circle(1.0f, 0.0f, 0.0f, 5);
}

void draw_blobSmall() {
	//SOMBRA
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	for (float angle = 0.0f; angle < 2 * 3.14159; angle += 0.1) {
		float x = sin(angle) * 20;
		float y = cos(angle) * 20;
		glVertex2f(x, y);
	}
	glEnd();

	//CORPO
	glColor3f(0.6, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(0, 50);
	glVertex2f(25, 10);
	glVertex2f(15, 0);
	glVertex2f(-15, 0);
	glVertex2f(-25, 10);
	glEnd();

	//BOCA
	glBegin(GL_POLYGON);
	glColor3f(0.4, 0.4, 0);
	glVertex2f(0, 30);
	glVertex2f(10, 22.5);
	glColor3f(1, 1, 0);
	glVertex2f(12, 15);
	glVertex2f(-12, 15);
	glColor3f(0.4, 0.4, 0);
	glVertex2f(-10, 22.5);
	glEnd();

	//DENTES
	glColor3f(0.09, 0.2, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-8, 15);
	glVertex2f(-5.5, 20);
	glVertex2f(-3, 15);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(8, 15);
	glVertex2f(5.5, 20);
	glVertex2f(3, 15);
	glEnd();

	//CABEÇA
	glColor3f(0.05, 0.05, 0.05);
	//glColor3f(0.1, 0.1, 0);
	glBegin(GL_POLYGON);
	glVertex2f(0, 20);
	glVertex2f(-10, 40);
	glVertex2f(10, 40);
	glEnd();

	//OLHOS
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-5, 32);
	glVertex2f(-1, 30);
	glVertex2f(-2, 35);
	glVertex2f(-5, 37);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(5, 32);
	glVertex2f(1, 30);
	glVertex2f(2, 34);
	glVertex2f(5, 36);
	glEnd();

	//SOMBRA
	glColor3f(0.4, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-25, 10);
	glVertex2f(-15, 0);
	glVertex2f(-10, 5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-15, 0);
	glVertex2f(15, 0);
	glVertex2f(15, 5);
	glVertex2f(-15, 5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-12, 15);
	glVertex2f(0, 8);
	glVertex2f(0, 15);
	glEnd();
	glColor3f(0.8, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(25, 10);
	glVertex2f(15, 0);
	glVertex2f(10, 5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(12, 15);
	glVertex2f(0, 8);
	glVertex2f(0, 15);
	glEnd();

}

void draw_blob_red_gib(void)
{
	//SOMBRA
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	for (float angle = 0.0f; angle < 2 * 3.14159; angle += 0.1) {
		float x = sin(angle) * 20;
		float y = cos(angle) * 10;
		glVertex2f(x, y);
	}
	glEnd();

	//CORPO
	glColor3f(0.6, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(0, 15);
	glVertex2f(25, 10);
	glVertex2f(15, 0);
	glVertex2f(-15, 0);
	glVertex2f(-25, 10);
	glEnd();

	//olhos fechados
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(4, 12);
	glVertex2f(8, 10);
	glBegin(GL_LINES);
	glVertex2f(8, 12);
	glVertex2f(4, 10);
	glBegin(GL_LINES);
	glVertex2f(-4, 12);
	glVertex2f(-8, 10);
	glVertex2f(-4, 10);
	glVertex2f(-8, 12);
	glEnd();

	//SOMBRA
	glColor3f(0.4, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-25, 10);
	glVertex2f(-15, 0);
	glVertex2f(-10, 5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-15, 0);
	glVertex2f(15, 0);
	glVertex2f(15, 5);
	glVertex2f(-15, 5);
	glEnd();

	glColor3f(0.6, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(25, 10);
	glVertex2f(15, 0);
	glVertex2f(10, 5);
	glEnd();

}

void draw_blobBig() {
	//SOMBRA
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	for (float angle = 0.0f; angle < 2 * 3.14159; angle += 0.1) {
		float x = sin(angle) * 20;
		float y = cos(angle) * 20;
		glVertex2f(x, y);
	}
	glEnd();

	//CORPO
	glColor3f(0.02, 0.4, 0);
	glBegin(GL_POLYGON);
	glVertex2f(0, 50);
	glVertex2f(25, 10);
	glVertex2f(15, 0);
	glVertex2f(-15, 0);
	glVertex2f(-25, 10);
	glEnd();

	//BOCA
	glBegin(GL_POLYGON);
	glColor3f(0.4, 0.4, 0);
	glVertex2f(0, 30);
	glVertex2f(10, 22.5);
	glColor3f(1, 1, 0);
	glVertex2f(12, 15);
	glVertex2f(-12, 15);
	glColor3f(0.4, 0.4, 0);
	glVertex2f(-10, 22.5);
	glEnd();

	//DENTES
	glColor3f(0.09, 0.2, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-8, 15);
	glVertex2f(-5.5, 20);
	glVertex2f(-3, 15);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(8, 15);
	glVertex2f(5.5, 20);
	glVertex2f(3, 15);
	glEnd();

	//CABEÇA
	glColor3f(0.05, 0.05, 0.05);
	//glColor3f(0.1, 0.1, 0);
	glBegin(GL_POLYGON);
	glVertex2f(0, 20);
	glVertex2f(-10, 40);
	glVertex2f(10, 40);
	glEnd();

	//OLHOS
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-5, 32);
	glVertex2f(-1, 30);
	glVertex2f(-2, 35);
	glVertex2f(-5, 37);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(5, 32);
	glVertex2f(1, 30);
	glVertex2f(2, 34);
	glVertex2f(5, 36);
	glEnd();

	//SOMBRA
	glColor3f(0.09, 0.2, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-25, 10);
	glVertex2f(-15, 0);
	glVertex2f(-10, 5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-15, 0);
	glVertex2f(15, 0);
	glVertex2f(15, 5);
	glVertex2f(-15, 5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-12, 15);
	glVertex2f(0, 8);
	glVertex2f(0, 15);
	glEnd();
	glColor3f(0.09, 0.3, 0);
	glBegin(GL_POLYGON);
	glVertex2f(25, 10);
	glVertex2f(15, 0);
	glVertex2f(10, 5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(12, 15);
	glVertex2f(0, 8);
	glVertex2f(0, 15);
	glEnd();

}

void draw_blob_green_gib(void)
{
	//SOMBRA
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	for (float angle = 0.0f; angle < 2 * 3.14159; angle += 0.1) {
		float x = sin(angle) * 20;
		float y = cos(angle) * 10;
		glVertex2f(x, y);
	}
	glEnd();

	//CORPO
	glColor3f(0.02, 0.4, 0);
	glBegin(GL_POLYGON);
	glVertex2f(0, 15);
	glVertex2f(25, 10);
	glVertex2f(15, 0);
	glVertex2f(-15, 0);
	glVertex2f(-25, 10);
	glEnd();

	//olhos fechados
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(4, 12);
	glVertex2f(8, 10);
	glBegin(GL_LINES);
	glVertex2f(8, 12);
	glVertex2f(4, 10);
	glBegin(GL_LINES);
	glVertex2f(-4, 12);
	glVertex2f(-8, 10);
	glVertex2f(-4, 10);
	glVertex2f(-8, 12);
	glEnd();

	//SOMBRA
	glColor3f(0.09, 0.2, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-25, 10);
	glVertex2f(-15, 0);
	glVertex2f(-10, 5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-15, 0);
	glVertex2f(15, 0);
	glVertex2f(15, 5);
	glVertex2f(-15, 5);
	glEnd();

	glColor3f(0.09, 0.3, 0);
	glBegin(GL_POLYGON);
	glVertex2f(25, 10);
	glVertex2f(15, 0);
	glVertex2f(10, 5);
	glEnd();
}

void draw_pickup() {

	//SOMBRA
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	for (float angle = 0.0f; angle < 2 * 3.14159; angle += 0.1) {
		float x = sin(angle) * 20;
		float y = cos(angle) * 20;
		glVertex2f(x, y);
	}
	glEnd();

	glColor3f(1, 0.4, 0.4);
	glBegin(GL_POLYGON);
	glVertex2f(-20, 50);
	glVertex2f(-10, 50);
	glVertex2f(-10, 40);
	glVertex2f(-20, 40);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(20, 50);
	glVertex2f(10, 50);
	glVertex2f(10, 40);
	glVertex2f(20, 40);
	glEnd();

	glColor3f(0.8, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(-30, 30);
	glVertex2f(-20, 30);
	glVertex2f(0, 10);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-30, 30);
	glVertex2f(-20, 30);
	glVertex2f(-20, 40);
	glVertex2f(-30, 40);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-30, 40);
	glVertex2f(-20, 40);
	glVertex2f(-20, 50);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(0, 30);
	glVertex2f(0, 40);
	glVertex2f(10, 50);
	glVertex2f(10, 40);
	glEnd();

	glColor3f(0.4, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-20, 30);
	glVertex2f(-20, 40);
	glVertex2f(-10, 40);
	glVertex2f(0, 30);
	glVertex2f(0, 10);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(20, 30);
	glVertex2f(20, 40);
	glVertex2f(10, 40);
	glVertex2f(0, 30);
	glVertex2f(0, 10);
	glEnd();

	glColor3f(0.6, 0, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(30, 30);
	glVertex2f(20, 30);
	glVertex2f(0, 10);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(30, 30);
	glVertex2f(20, 30);
	glVertex2f(20, 40);
	glVertex2f(30, 40);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(30, 40);
	glVertex2f(20, 40);
	glVertex2f(20, 50);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(0, 30);
	glVertex2f(0, 40);
	glVertex2f(-10, 50);
	glVertex2f(-10, 40);
	glEnd();
}

void draw_jar() {

	//SOMBRA
	glColor3f(0, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	for (float angle = 0.0f; angle < 2 * 3.14159; angle += 0.1) {
		float x = sin(angle) * 27.5;
		float y = cos(angle) * 27.5;
		glVertex2f(x, y);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.4, 0);
	glVertex2f(-30, 10);
	glVertex2f(-30, 45);
	glVertex2f(-10, 60);
	glVertex2f(10, 60);
	glVertex2f(30, 45);
	glVertex2f(30, 10);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-15, 80);
	glVertex2f(-15, 85);
	glVertex2f(15, 85);
	glVertex2f(15, 80);
	glEnd();

	glColor3f(0.6, 0.3, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-10, 60);
	glVertex2f(-10, 80);
	glVertex2f(10, 80);
	glVertex2f(10, 60);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-20, 0);
	glVertex2f(-30, 10);
	glVertex2f(30, 10);
	glVertex2f(20, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-30, 30);
	glVertex2f(30, 30);
	glVertex2f(30, 27.5);
	glVertex2f(-30, 27.5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-30, 15);
	glVertex2f(30, 15);
	glVertex2f(30, 12.5);
	glVertex2f(-30, 12.5);
	glEnd();

	glColor3f(0.19, 0.34, 0.41);
	glBegin(GL_POLYGON);
	glVertex2f(-35, 15);
	glVertex2f(-35, 25);
	glVertex2f(35, 25);
	glVertex2f(35, 15);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-35, 30);
	glVertex2f(-35, 40);
	glVertex2f(35, 40);
	glVertex2f(35, 30);
	glEnd();
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON);
	glVertex2f(-25, 30);
	glVertex2f(-25, 40);
	glVertex2f(-15, 40);
	glVertex2f(-15, 30);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-25, 15);
	glVertex2f(-25, 25);
	glVertex2f(-15, 25);
	glVertex2f(-15, 15);
	glEnd();
}

void draw_jar_gib(void)
{
	//SOMBRA
	glColor3f(0, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	for (float angle = 0.0f; angle < 2 * 3.14159; angle += 0.1) {
		float x = sin(angle) * 27.5;
		float y = cos(angle) * 27.5;
		glVertex2f(x, y);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.3, 0);
	glVertex2f(-30, 10);
	glVertex2f(-30, 40);
	glVertex2f(-20, 30);
	glVertex2f(-10, 45);
	glVertex2f(-5, 35);
	glVertex2f(0, 25);
	glVertex2f(10, 35);
	glVertex2f(20, 20);
	glVertex2f(30, 40);
	glVertex2f(30, 20);
	glVertex2f(30, 10);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.4, 0);
	glVertex2f(-30, 10);
	glVertex2f(-30, 20);
	glVertex2f(30, 20);
	glVertex2f(30, 10);
	glEnd();

	glColor3f(0.6, 0.3, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-20, 0);
	glVertex2f(-30, 10);
	glVertex2f(30, 10);
	glVertex2f(20, 0);
	glEnd();

	glColor3f(0.19, 0.34, 0.41);
	glBegin(GL_POLYGON);
	glVertex2f(-35, 15);
	glVertex2f(-35, 25);
	glVertex2f(35, 25);
	glVertex2f(35, 15);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex2f(-25, 15);
	glVertex2f(-25, 25);
	glVertex2f(-15, 25);
	glVertex2f(-15, 15);
	glEnd();

	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON);
	glVertex2f(-25, 15);
	glVertex2f(-25, 25);
	glVertex2f(-15, 25);
	glVertex2f(-15, 15);
	glEnd();

}

void draw_rock() {

	//SOMBRA
	glColor3f(0, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	for (float angle = 0.0f; angle < 2 * 3.14159; angle += 0.1) {
		float x = sin(angle) * 30;
		float y = cos(angle) * 25;
		glVertex2f(x, y);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
	glVertex2f(-10, 30);
	glVertex2f(-20, 30);
	glVertex2f(-20, 40);
	glVertex2f(-10, 50);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-10, 10);
	glVertex2f(-25, 10);
	glVertex2f(-25, 20);
	glVertex2f(-20, 30);
	glVertex2f(-10, 30);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(20, 45);
	glVertex2f(30, 25);
	glVertex2f(30, 5);
	glVertex2f(20, 5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(0, 50);
	glVertex2f(20, 50);
	glVertex2f(20, -10);
	glVertex2f(0, -10);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(20, 40);
	glVertex2f(30, 20);
	glVertex2f(30, 0);
	glVertex2f(20, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-10, 20);
	glVertex2f(-20, 20);
	glVertex2f(-20, 30);
	glVertex2f(-10, 40);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-10, 0);
	glVertex2f(-25, 0);
	glVertex2f(-25, 10);
	glVertex2f(-20, 20);
	glVertex2f(-10, 20);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(10, 20);
	glVertex2f(20, 20);
	glVertex2f(20, -15);
	glVertex2f(10, -15);
	glEnd();

	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(-10, 0);
	glVertex2f(0, -10);
	glVertex2f(0, 50);
	glVertex2f(-10, 60);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(5, -10);
	glVertex2f(10, -15);
	glVertex2f(10, 20);
	glVertex2f(5, 30);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(20, -15);
	glVertex2f(25, -10);
	glVertex2f(25, 30);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(10, 20);
	glEnd();

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(5, 30);
	glVertex2f(25, 30);
	glVertex2f(10, 20);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-10, 60);
	glVertex2f(0, 50);
	glVertex2f(20, 50);
	glVertex2f(20, 60);
	glVertex2f(10, 70);
	glVertex2f(0, 70);
	glEnd();
}

void draw_tree() {

	//SOMBRA
	glColor3f(0, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	for (float angle = 0.0f; angle < 2 * 3.14159; angle += 0.1) {
		float x = sin(angle) * 20;
		float y = cos(angle) * 20;
		glVertex2f(x, y);
	}
	glEnd();

	//CIMA
	glColor3f(0.4, 0.4, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-35, 40);
	glVertex2f(-25, 30);
	glVertex2f(25, 30);
	glVertex2f(35, 40);
	glVertex2f(35, 50);
	glVertex2f(10, 80);
	glVertex2f(-10, 80);
	glVertex2f(-35, 50);
	glEnd();
	//SOMBRA
	glColor3f(0.09, 0.2, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-35, 40);
	glVertex2f(-25, 30);
	glVertex2f(-25, 20);
	glVertex2f(-35, 30);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-25, 30);
	glVertex2f(25, 30);
	glVertex2f(25, 20);
	glVertex2f(-25, 20);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(35, 40);
	glVertex2f(25, 30);
	glVertex2f(25, 20);
	glVertex2f(35, 30);
	glEnd();

	//TRONCO
	glColor3f(0.4, 0.2, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-15, 0);
	glVertex2f(15, 0);
	glVertex2f(5, 10);
	glVertex2f(-5, 10);
	glEnd();
	glColor3f(0.4, 0.2, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-5, 10);
	glVertex2f(-5, 25);
	glVertex2f(5, 25);
	glVertex2f(5, 10);
	glEnd();
	//SOMBRA
	glColor3f(0.2, 0.09, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-5, 25);
	glVertex2f(5, 25);
	glVertex2f(5, 15);
	glVertex2f(-5, 15);
	glEnd();
}

void draw_playerSword() {

	//PUNHO
	//POMO
	glColor3f(1, 0.5, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, 0);
	glVertex2f(0.5, 0);
	glVertex2f(0.5, -1);
	glVertex2f(-0.5, -1);
	glEnd();
	//SOMBRA-POMO
	glColor3f(0, 0.3, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, 0);
	glVertex2f(-0.3, -0.3);
	glVertex2f(-0.3, -0.7);
	glVertex2f(-0.5, -1);
	glEnd();
	glColor3f(0, 0.2, 0.4);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, 0);
	glVertex2f(0.5, 0);
	glVertex2f(0.3, -0.3);
	glVertex2f(-0.3, -0.3);
	glEnd();
	glColor3f(0, 0.4, 0.8);
	glBegin(GL_POLYGON);
	glVertex2f(0.5, 0);
	glVertex2f(0.3, -0.3);
	glVertex2f(0.3, -0.7);
	glVertex2f(0.5, -1);
	glEnd();
	glColor3f(1, 0.7, 0.4);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, -1);
	glVertex2f(0.5, -1);
	glVertex2f(0.3, -0.7);
	glVertex2f(-0.3, -0.7);
	glEnd();

	//CABO
	glColor3f(0.2, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.2, -1);
	glVertex2f(0.2, -1);
	glVertex2f(0.6, -4);
	glVertex2f(-0.6, -4);
	glEnd();
	glColor3f(0.6, 0.3, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.05, -1);
	glVertex2f(0.05, -1);
	glVertex2f(0.4, -4);
	glVertex2f(-0.4, -4);
	glEnd();

	//CHAPPE
	glColor3f(1, 0.5, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-1, -4);
	glVertex2f(1, -4);
	glVertex2f(1, -6);
	glVertex2f(-1, -6);
	glEnd();
	glColor3f(0.8, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.4, -4.6);
	glVertex2f(0.4, -4.6);
	glVertex2f(0.4, -5.4);
	glVertex2f(-0.4, -5.4);
	glEnd();
	//SOMBRA-CHAPPE
	glColor3f(0, 0.3, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(-1, -6);
	glVertex2f(-0.7, -5.7);
	glVertex2f(-0.7, -4.3);
	glVertex2f(-1, -4);
	glEnd();
	glColor3f(0, 0.2, 0.4);
	glBegin(GL_POLYGON);
	glVertex2f(-1, -4);
	glVertex2f(1, -4);
	glVertex2f(0.7, -4.3);
	glVertex2f(-0.7, -4.3);
	glEnd();
	glColor3f(0, 0.4, 0.8);
	glBegin(GL_POLYGON);
	glVertex2f(1, -6);
	glVertex2f(0.7, -5.7);
	glVertex2f(0.7, -4.3);
	glVertex2f(1, -4);
	glEnd();
	glColor3f(1, 0.7, 0.4);
	glBegin(GL_POLYGON);
	glVertex2f(1, -6);
	glVertex2f(-1, -6);
	glVertex2f(-0.7, -5.7);
	glVertex2f(0.7, -5.7);
	glEnd();

	//GUARDA-MAO
	glColor3f(1, 0.7, 0.4);
	glBegin(GL_TRIANGLES);
	glVertex2f(-4, -6);
	glVertex2f(-1, -4.3);
	glVertex2f(-1, -5.6);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(4, -6);
	glVertex2f(1, -4.3);
	glVertex2f(1, -5.6);
	glEnd();
	glColor3f(1, 0.5, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(3.2, -5.7);
	glVertex2f(1, -4.5);
	glVertex2f(1, -5.4);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(-3.2, -5.7);
	glVertex2f(-1, -4.5);
	glVertex2f(-1, -5.4);
	glEnd();

	//LAMINA
	glColor3f(0.6, 0.8, 1);
	glBegin(GL_POLYGON);
	glVertex2f(-0.6, -6);
	glVertex2f(0, -6);
	glVertex2f(0, -20);
	glVertex2f(-0.6, -19);
	glEnd();
	glColor3f(0.8, 0.9, 1);
	glBegin(GL_POLYGON);
	glVertex2f(0.6, -6);
	glVertex2f(0, -6);
	glVertex2f(0, -20);
	glVertex2f(0.6, -19);
	glEnd();
	glColor3f(0.4, 0.7, 1);
	glBegin(GL_POLYGON);
	glVertex2f(0.2, -6);
	glVertex2f(-0.2, -6);
	glVertex2f(-0.2, -17);
	glVertex2f(0.2, -17);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(0.2, -17);
	glVertex2f(-0.2, -17);
	glVertex2f(0, -19);
	glEnd();
}

void draw_hitMarker() {

	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-35, -25);
	glVertex2f(-25, -35);
	glVertex2f(-5, -15);
	glVertex2f(-15, -5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(35, -25);
	glVertex2f(25, -35);
	glVertex2f(5, -15);
	glVertex2f(15, -5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(35, 25);
	glVertex2f(25, 35);
	glVertex2f(5, 15);
	glVertex2f(15, 5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-35, 25);
	glVertex2f(-25, 35);
	glVertex2f(-5, 15);
	glVertex2f(-15, 5);
	glEnd();

}


void write(int width, int height, int x, int y, void* font, char* string) {
	float xxx = (float)x;
	float yyy = (float)y;
	int len, i;
	len = (int)strlen(string);
	glColor3f(1, 0, 0);
	glRasterPos2f(xxx, yyy);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(font, string[i]);
	}
}


void Draw(struct Entity* entity) {
	switch (entity->kind) {

	case 0: //Palyer
		if (entity->frame[2]) {
			glScalef(.25f, .25f, 1.0f);
			glTranslatef(entity->position.x * 4, entity->position.y * 4, entity->position.y + 125);
			draw_player();
		}
		break;
		
	case 1: //Enemy Thrower
		glScalef(.25f, .25f, 1.0f);
		glTranslatef(entity->position.x * 4, entity->position.y * 4, entity->position.y + 125);
		draw_thrower();
		break;

	case 2: //Enemy Thrower Projectile
		glScalef(1.0f, 1.0f, 1.0f);
		glTranslatef(entity->position.x, entity->position.y, entity->position.y + 125);
		draw_throwerProjectile();
		break;

	case 3: //Enemy Blob Small
		glScalef(.25f, .25f, 1.0f);
		glTranslatef(entity->position.x * 4, entity->position.y * 4, entity->position.y + 125);
		draw_blobSmall();
		break;

	case 4: //Enemy Blob Big
		glScalef(.5f, .5f, 1.0f);
		glTranslatef(entity->position.x * 2, entity->position.y * 2, entity->position.y + 125);
		draw_blobBig();
		break;

	case 5: //PickUp
		glScalef(.25f, .25f, 1.0f);
		glTranslatef(entity->position.x * 4, entity->position.y * 4, entity->position.y + 125);
		draw_pickup();
		break;
		
	case 6: //Jar
		glScalef(.18f, .18f, 1.0f);
		glTranslatef(entity->position.x * 5.5 + 8.0, entity->position.y * 5.5 + 8.0, entity->position.y + 125);
		draw_jar();
		break;
		
	case 7: //Block
		if (entity->frame_imunity == 1) {
			glScalef(.25f, .25f, 1.0f);
			glTranslatef(entity->position.x * 4, entity->position.y * 4, entity->position.y + 125);
			draw_rock();
		}
		else
		{
			glScalef(.25f, .25f, 1.0f);
			glTranslatef(entity->position.x * 4, entity->position.y * 4, entity->position.y + 125);
			draw_tree();
		}
		break;

	case 8: {
		float angle;
		if (entity->direction.x == 0) angle = asin(entity->direction.y);
		else angle = acos(entity->direction.x);
		angle = angle * 180.0 / 3.141593 + 67.5 + 45 * entity->frame[0] / 3;

		glScalef(1.5f, 1.5f, 1.0f);
		glTranslatef((entity->position.x - entity->direction.x * 10) * .66667, (entity->position.y - entity->direction.y * 10) * .66667, entity->position.y + 125);
		glRotatef(angle, 0, 0, 1);

		draw_playerSword();
	} break; //Palyer Sword

	case 9: //Particle
		switch (entity->health) {
		case 0: //HitMarker
			glScalef(.25f, .25f, 1.0f);
			glTranslatef(entity->position.x * 4, entity->position.y * 4, .5);
			draw_hitMarker();
			break;

		case 1: //Thrower Corpse
			glScalef(.25f, .25f, 1.0f);
			glTranslatef(entity->position.x * 4, entity->position.y * 4, entity->position.y + 125);
			draw_skelet_gib();
			break;

		case 2: //BlobSmall Corpse
			glScalef(.25f, .25f, 1.0f);
			glTranslatef(entity->position.x * 4, entity->position.y * 4, entity->position.y + 125);
			draw_blob_red_gib();
			break;

		case 3: //BlobBig Corpse
			glScalef(.5f, .5f, 1.0f);
			glTranslatef(entity->position.x * 2, entity->position.y * 2, entity->position.y + 125);
			draw_blob_green_gib();
			break;

		case 4: //BrokenJar
			glScalef(.18f, .18f, 1.0f);
			glTranslatef(entity->position.x * 5.5 + 8.0, entity->position.y * 5.5 + 8.0, entity->position.y + 125);
			draw_jar_gib();
			break;

		case 5: //ProjectileGibs
			glScalef(.125f, .125f, 1.0f);
			glTranslatef(entity->position.x * 8, entity->position.y * 8, entity->position.y + 125);
			draw_hitMarker();
			glRotatef(45, 0, 0, 1);
			draw_hitMarker();
			break;
			break;
		}
		break; 
	}

	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}