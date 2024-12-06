#pragma once

#include "PathFindingAlgorithm.h"

class PathFindingDFS : public PathFindingAlgorithm
{

public:
	PathFindingDFS(Grid* grid) : PathFindingAlgorithm(grid) {}
	virtual void FindPath(Agent* agent, float dTime) override;

};

