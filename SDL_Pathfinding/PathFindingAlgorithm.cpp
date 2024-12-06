#include "PathFindingAlgorithm.h"

PathFindingAlgorithm::PathFindingAlgorithm(Grid* _grid)
{
	start = new Node(0, 0, 0);
	goal = new Node(0, 0, 0);

	grid = _grid;
}

void PathFindingAlgorithm::FindPath(Agent* agent, float dTime)
{
}
