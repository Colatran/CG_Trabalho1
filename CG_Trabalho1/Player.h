#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(float x, float y);
	~Player();
	void draw() override;
	void die() override;
	void reactToEntity(Entity *entity) override;
};

