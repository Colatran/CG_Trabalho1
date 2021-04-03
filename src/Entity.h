#pragma once
#include "Map.h"

#define ORIGIN 125 //500 / 4
#define MAP Map::ref

class Entity {
public:
	static Entity* entities[];
	static bool slots[];

	/// <summary>
	/// 0-default
	/// 1-player
	/// 2-enemy
	/// 3-pickup
	/// </summary>
	int kind = 0;
	int slot = 0;
	float posX = 0;	float posY = 0;	//position
	float dirX = 0; float dirY = 0; //moving vector
	float speed = 1;
	float box = 0;	//collision box radius

	//METHODS
	virtual void draw();
	virtual void die();
	virtual void reactToEntity(Entity* entity);

	void move();
	void collision();
protected:
	float distanceTo(float x, float y);

	static void spawn(Entity* entity);
	static void despawn(int index);
private:
	static int nextFreeSlot();
};

