#pragma once
#include "Entity.h"


using namespace std;

class Pickup : public Entity {
public:
	Pickup(Vector location);
	~Pickup();
	void draw() override;
	void die() override;
};

