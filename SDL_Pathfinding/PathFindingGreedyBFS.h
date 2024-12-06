#pragma once

#include "PathFindingAlgorithm.h"

class PathFindingGreedyBFS : public PathFindingAlgorithm
{
public:
	PathFindingGreedyBFS() { new PathFindingAlgorithm(); }
	virtual void FindPath(Agent* agent, float dTime) override;
};

