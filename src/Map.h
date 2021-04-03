#pragma once
class Map
{

public:
	static Map *ref;
	float radius = 70.0f;

	Map();
	void draw();
	void DecreaseMap();
	void IncreaseMap();
};

