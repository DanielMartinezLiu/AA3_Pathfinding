#pragma once

#include "PathFindingAlgorithm.h"

class PathFindingAStar : public PathFindingAlgorithm
{
public:
	PathFindingAStar(Grid* grid) : PathFindingAlgorithm(grid) {}
	virtual void FindPath(Agent* agent, float dTime) override;
};

