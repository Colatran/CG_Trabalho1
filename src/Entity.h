#pragma once
#include <math.h>
#include <stdio.h>


struct Vector {
	float x;
	float y;
};

struct Entity {
	struct Vector position;
	struct Vector direction;
	struct Vector AIpoint;
	float speed;

	/// <summary>
	/// <para>Isto controla o que acontece a duas entidades colidem uma com a outra</para>
	/// <para>0 rigid							</para>
	/// <para>1 player __ -1 friendly hazard	</para>
	/// <para>2 hostile__ -2 hostile  hazard	</para>
	/// <para>3 pickup							</para>
	/// </summary>
	int surface;
	float radius;	//collision box radius
	/// <summary>
	/// <para>0 player							</para>
	/// <para>1 enemy thrower					</para>
	/// <para>2 enemy thrower projectile		</para>
	/// <para>3 enemy blob Small				</para>
	/// <para>4 enemy blob Big					</para>
	/// <para>5 pickup							</para>
	/// <para>6 jar								</para>
	/// <para>7 block							</para>
	/// <para>8 playerSword						</para>
	/// <para>9 particle						</para>
	/// </summary>
	int kind;
	int health;

	int frame[3];
	int frame_imunity;
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
	vector.x = (x / magnitude) * length / 2;
	vector.y = (y / magnitude) * length / 2;
	return vector;
}

int IsInsideMyBoundries_Circle(struct Entity* me, struct Entity* him) {
	if (Distance(&me->position, &him->position) < me->radius) return 1;
	else return 0;
}

//Enteties
struct Entity Player() {
	struct Entity entity;
	entity.position.x = 0;
	entity.position.y = 0;
	entity.direction.x = 0;
	entity.direction.y = -1;
	entity.speed = 0;

	entity.surface = 1;
	entity.radius = 10;
	entity.kind = 0;
	entity.health = 1;
	entity.frame[0] = 0;
	entity.frame[1] = 0;
	entity.frame[2] = 1;
	entity.frame_imunity = 0;
	return entity;
}

struct Entity PlayerSword(struct Entity player) {
	struct Entity entity;
	entity.position.x = player.position.x + player.direction.x * player.radius;
	entity.position.y = player.position.y + player.direction.y * player.radius;
	entity.direction = player.direction;

	entity.surface = -1;
	entity.radius = 25;
	entity.kind = 8;
	entity.frame[0] = 0;
	return entity;
}

struct Entity PickUp(struct Vector position) {
	struct Entity entity;
	entity.position = position;

	entity.surface = 3;
	entity.radius = 10;
	entity.kind = 5;
	entity.health = 1;
	entity.frame_imunity = 10;
	return entity;
}

struct Entity Jar(struct Vector position) {
	struct Entity entity;
	entity.position = position;

	entity.surface = 0;
	entity.radius = 10;
	entity.kind = 6;
	entity.health = 1;

	return entity;
}

struct Entity Block(struct Vector position) {
	struct Entity entity;
	entity.position = position;

	entity.surface = 0;
	entity.radius = 10;
	entity.kind = 7;
	entity.frame_imunity = rand() % 2;
	return entity;
}

/// <summary>
/// <para>Type:</para>
/// <para>0 hitMarker			</para>
/// <para>1 Thrower Corpse		</para>
/// <para>2 BlobSmall Corpse	</para>
/// <para>3 BlobBig Corpse		</para>
/// <para>4 BrokenJar			</para>
/// <para>5 ProjectileGibs		</para>
/// </summary>
struct Entity Particle(struct Vector position, int type, int time) {
	struct Entity entity;
	entity.position = position;

	entity.radius = 0;
	entity.kind = 9;
	entity.frame_imunity = time;

	//Isto vai defenir que particula parace no ecra
	entity.health = type;
	return entity;
}

struct Entity Thrower(struct Vector position) {
	struct Entity entity;
	entity.position = position;
	entity.direction.x = 0;
	entity.direction.y = 0;
	entity.speed = 0;

	entity.surface = 2;
	entity.radius = 10;
	entity.kind = 1;
	entity.health = 2;

	entity.frame_imunity = 0;
	entity.frame[0] = 4;
	entity.frame[1] = 0;

	return entity;
}

struct Entity ThrowerRock(struct Vector position, struct Vector direction) {
	struct Entity entity;
	entity.position = position;
	entity.direction = direction;
	entity.speed = 5;

	entity.surface = -2;
	entity.radius = 10;
	entity.kind = 2;
	entity.frame_imunity = 0;

	return entity;
}

struct Entity BlobSmall(struct Vector position) {
	struct Entity entity;
	entity.position = position;
	entity.direction.x = 0;
	entity.direction.y = 0;
	entity.speed = 0;

	entity.surface = 2;
	entity.radius = 10;
	entity.kind = 3;

	entity.frame_imunity = 0;
	entity.frame[0] = 2;
	entity.frame[1] = 60;
	entity.frame[2] = 0;

	return entity;
}

struct Entity BlobBig(struct Vector position) {
	struct Entity entity;
	entity.position = position;
	entity.direction.x = 0;
	entity.direction.y = 0;
	entity.speed = 0;

	entity.surface = 2;
	entity.radius = 20;
	entity.kind = 4;
	entity.health = 2;

	entity.frame_imunity = 0;
	entity.frame[0] = 2;
	entity.frame[1] = 60;
	entity.frame[2] = 0;

	return entity;
}
