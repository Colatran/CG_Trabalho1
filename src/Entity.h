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
	/// <para>0 default	</para>
	/// <para>1 player __ -1 friendly hazard	</para>
	/// <para>2 enemy  __ -2 hostile  hazard	</para>
	/// <para>3 pickup	</para>
	/// </summary>
	int kind = 0;
	int slot = 0;
	Vector position;
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

