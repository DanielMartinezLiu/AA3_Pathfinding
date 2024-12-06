#pragma once

#include "PathFindingAlgorithm.h"

class PathFindingDFS : public PathFindingAlgorithm
{
public:
	PathFindingDFS() { new PathFindingAlgorithm(); }
	virtual void FindPath(Agent* agent, float dTime) override;

};

