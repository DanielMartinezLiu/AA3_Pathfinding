#pragma once

#include "PathFindingAlgorithm.h"

class PathFindingDijkstra : public PathFindingAlgorithm
{
public:
	PathFindingDijkstra() { new PathFindingAlgorithm(); }
	virtual void FindPath(Agent* agent, float dTime) override;

};

