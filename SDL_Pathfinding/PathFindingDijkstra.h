#pragma once

#include "PathFindingAlgorithm.h"

class PathFindingDijkstra : public PathFindingAlgorithm
{
public:
	virtual void FindPath(Agent* agent, float dTime) override;
};

