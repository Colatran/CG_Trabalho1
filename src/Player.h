#pragma once
#include "Entity.h"

class Player : public Entity {
public:
	Vector velocity;
private:
	const float speed = 2;

public:
	Player(Vector location);
	~Player();
	void draw() override;
	void move() override;
	void die() override;
protected:
	void reactToEntity(Entity *entity) override;
};

