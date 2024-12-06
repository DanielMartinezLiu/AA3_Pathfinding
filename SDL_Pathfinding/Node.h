#pragma once

#include "Vector2D.h"
#include "utils.h"

class Node
{
private:
	int x;
	int y;
	int type;
	bool drawed;

public:
	Node(int _x, int _y) 
		: x(_x), y(_y) {}

	Node(int _x, int _y, int _type)
		: x(_x), y(_y), type(_type), drawed(false){}

	int getX() const { return x; }
	int getY() const { return y; }
	int getType() const { return type; }
	bool getDrawed() const { return drawed; }

	void setDrawed(bool _drawed) { drawed = _drawed; }

	void draw(Vector2D position);

	bool operator==(const Node& other) const {
		return x == other.x && y == other.y;
	}

};