#pragma once
#include "Utils.h"

class Map {
public:
	static Map *ref;
	float radius = 70.0f;

	Map();
	void draw();
	void DecreaseMap();
	void IncreaseMap();
	static float RandomFloat(float min, float max);
	static Vector RandomPosition();
};