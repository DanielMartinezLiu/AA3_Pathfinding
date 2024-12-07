#pragma once

#include "PathFindingAlgorithm.h"

class PathFindingGreedyBFS : public PathFindingAlgorithm
{
public:
	PathFindingGreedyBFS(Grid* grid) : PathFindingAlgorithm(grid) {}
	virtual void FindPath(Agent* agent, float dTime) override;
};

