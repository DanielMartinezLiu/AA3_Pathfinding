#pragma once

#include "PathFindingAlgorithm.h"

class PathFindingDijkstra : public PathFindingAlgorithm
{
public:
	PathFindingDijkstra(Grid* grid) : PathFindingAlgorithm(grid) {}

	virtual void FindPath(Agent* agent, float dTime) override;

};

