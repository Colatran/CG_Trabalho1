#pragma once
#define ORIGIN 125 //500 / 4

struct Vector {
	float x;
	float y;

	Vector() {
		x = ORIGIN;
		y = ORIGIN;
	};
	Vector(float X, float Y) {
		x = X;
		y = Y;
	}

	static Vector zero;
	static Vector one;
	static Vector origin;
};