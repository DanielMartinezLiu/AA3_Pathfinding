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

	float elapsedTime;
	std::vector<Node*> nodes;
	bool goalReached;

public:
	PathFindingAlgorithm(Grid* _grid);

	virtual void FindPath(Agent* agent, float dTime);
	virtual void RecoverPath(Agent* agent);

	virtual void resetNodes();
	void draw();


	void setStart(Node* _start) { start = _start; }
	void setGoal(Node* _goal) { goal = _goal; }
	void setGrid(Grid* _grid) { grid = _grid; }
};