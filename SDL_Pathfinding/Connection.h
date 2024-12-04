#pragma once

#include "Node.h"
class Connection
{
private:
	Node* nodeFrom;
	Node* nodeTo;
public:
	float weight;

	Node* GetNodeFrom() { return nodeFrom; }
	Node* GetNodeTo() { return nodeTo; }
};