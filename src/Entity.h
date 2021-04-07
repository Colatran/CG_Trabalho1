#pragma once
#include <math.h>
#define ORIGIN 125 //500 / 4
#define PLAYER_MAXSPEED 3


struct Vector {
	float x;
	float y;
};
struct Entity {
	struct Vector position;
	struct Vector direction;
	float speed;
	float penaltySpeed;
	/// <summary>
	/// <para>Isto controla o que acontece a duas entidades colidem uma com a outra</para>
	/// <para>0 rigid	</para>
	/// <para>1 player __ -1 friendly hazard	</para>
	/// <para>2 hostile__ -2 hostile  hazard	</para>
	/// <para>3 pickup	</para>
	/// <para>4 destructible	</para>
	/// </summary>
	int surface;
	float radius;	//collision box radius
	/// <summary>
	/// <para>0 player	</para>
	/// <para>1 pickup	</para>
	/// <para>2 block	</para>
	/// </summary>
	int kind;
	int slot;
};



//Utils
float Distance(struct Vector* pointA, struct Vector* pointB) {
	return sqrt(
		(pointA->x - pointB->x) * (pointA->x - pointB->x) +
		(pointA->y - pointB->y) * (pointA->y - pointB->y)
	);
}
struct Vector SetVectorLength(float x, float y, float length) {
	float magnitude = sqrt(x * x + y * y);
	struct Vector vector;
	vector.x = (x / magnitude) * length/2;
	vector.y = (y / magnitude) * length/2;
	return vector;//
}


struct Entity Player() {
	struct Entity entity;
	entity.position.x = ORIGIN;
	entity.position.y = ORIGIN;
	entity.direction.x = 0;
	entity.direction.y = -1;
	entity.speed = 0;
	entity.penaltySpeed = 1;
	entity.surface = 1;
	entity.radius = 10;
	entity.kind = 0;
	return entity;
}
struct Entity PickUp(struct Vector position) {
	struct Entity entity;
	entity.position.x = position.x;
	entity.position.y = position.y;
	entity.surface = 3;
	entity.radius = 10;
	entity.kind = 1;
	return entity;
}
struct Entity Block(struct Vector position) {
	struct Entity entity;
	entity.position.x = position.x;
	entity.position.y = position.y;
	entity.surface = 0;
	entity.radius = 10;
	entity.kind = 2;
	return entity;
}

int IsInsideMyBoundries_Circle(struct Entity *me, struct Entity *him) {
	if (Distance(&me->position, &him->position) < me->radius) return 1;
	else return 0;
}
/*int IsInsideMyBoundries_Square(struct Entity *me, struct Entity *him) {
	if (me->position.x - me->radius > him->position.x + him->radius ||
		me->position.x + me->radius < him->position.x - him->radius ||
		me->position.y - me->radius > him->position.y + him->radius ||
		me->position.y + me->radius < him->position.y - him->radius) return 1;
	else return 0;
}*/