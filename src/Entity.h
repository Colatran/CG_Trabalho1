#pragma once
#define ORIGIN 125 //500 / 4
#define RAND_MAX 32767

#define PLAYER_SPEED 2

struct Vector {
	float x;
	float y;
};
struct Entity {
	struct Vector position;
	struct Vector velocity;
	float speed;
	/// <summary>
	/// <para>Isto controla o que acontece a duas entidades colidem uma com a outra</para>
	/// <para>0 default	</para>
	/// <para>1 player __ -1 friendly hazard	</para>
	/// <para>2 enemy  __ -2 hostile  hazard	</para>
	/// <para>3 pickup	</para>
	/// </summary>
	int surface;
	float box;	//collision box radius
	/// <summary>
	/// <para>Isto controla desenho que a entidde tem</para>
	/// <para>0 player	</para>
	/// <para>1 pickup	</para>
	/// </summary>
	int kind;
	int slot;
};

struct Entity Player() {
	struct Entity entity;
	entity.position.x = ORIGIN;
	entity.position.y = ORIGIN;
	entity.velocity.x = 0;
	entity.velocity.y = 0;
	entity.speed = 0;
	entity.surface = 1;
	entity.box = 10;
	entity.kind = 0;
	return entity;
}
struct Entity PickUp(struct Vector position) {
	struct Entity entity;
	entity.position.x = position.x;
	entity.position.y = position.y;
	entity.velocity.x = 0;
	entity.velocity.y = 0;
	entity.speed = 0;
	entity.surface = 3;
	entity.box = 10;
	entity.kind = 1;
	return entity;
}

void Move_Player(struct Entity* entity) {
	entity->position.x += entity->velocity.x * PLAYER_SPEED;
	entity->position.y += entity->velocity.y * PLAYER_SPEED;
	entity->velocity.x = 0;
	entity->velocity.y = 0;
}

void Collision_Player() {

}