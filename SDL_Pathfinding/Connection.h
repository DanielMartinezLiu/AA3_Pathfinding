#pragma once

#include "Node.h"
class Connection
{
private:
	Node* nodeFrom;
	Node* nodeTo;
	float weight;
public:

	Connection(Node* _nodeFrom, Node* _nodeTo, float _weight)
		:nodeFrom(_nodeFrom), nodeTo(_nodeTo), weight(_weight){}

	Node* getNodeFrom() const { return nodeFrom; }
	Node* getNodeTo() const { return nodeTo; }
	float getWeight() const { return weight; }
};