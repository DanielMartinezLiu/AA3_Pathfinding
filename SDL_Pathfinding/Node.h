#pragma once
class Node
{
private:
	int x;
	int y;

public:
	Node(int _x, int _y) 
		: x(_x), y(_y) {}

	int getX() const { return x; }
	int getY() const { return y; }


	bool operator==(const Node& other) const {
		return x == other.x && y == other.y;
	}
};