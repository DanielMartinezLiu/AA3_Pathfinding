#pragma once

// Referencia cruzada con agent, pero lo pide el profe asi en el UML
#include "Agent.h"
#include "Grid.h"

class PathFindingAlgorithm
{
protected:
	Node* start;
	Node* goal;
	Grid* grid;

public:
	PathFindingAlgorithm(Grid* _grid);

	virtual void FindPath(Agent* agent, float dTime);

	void setStart(Node* _start) { start = _start; }
	void setGoal(Node* _goal) { goal = _goal; }
	void setGrid(Grid* _grid) { grid = _grid; }
};