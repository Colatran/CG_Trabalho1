#pragma once
#include "Map.h"
#include "Utils.h"
#include <gl/glut.h>
#include <math.h>

#define ORIGIN 125 //500 / 4
#define MAP Map::ref

class Entity {
public:
	static Entity* entities[];
	static bool slots[];

	/// <summary>
	/// 0-default
	/// 1-player
	/// 2-pickup
	/// </summary>
	int kind = 0;
	int slot = 0;
	Vector position;
	Vector velocity;
	float box = 0;	//collision box radius

	//METHODS
	virtual void draw();
	virtual void move();
	virtual void die();
	void collision();
protected:
	virtual void reactToEntity(Entity* entity);
	float distanceTo(Vector point);
	static void spawn(Entity* entity);
	static void despawn(int index);
private:
	static int nextFreeSlot();
};

