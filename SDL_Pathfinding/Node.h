#pragma once
class Node
{
private:
	int x;
	int y;
	int type;

public:
	Node(int _x, int _y) 
		: x(_x), y(_y) {}

	Node(int _x, int _y, int _type)
		: x(_x), y(_y), type(_type) {}

	int getX() const { return x; }
	int getY() const { return y; }
	int getType() const { return type; }

	bool operator==(const Node& other) const {
		return x == other.x && y == other.y;
	}

};