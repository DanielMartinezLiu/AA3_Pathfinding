#pragma once

#include "PathFindingAlgorithm.h"

class PathFindingAStar : public PathFindingAlgorithm
{
public:
	PathFindingAStar() { new PathFindingAlgorithm(); }
	virtual void FindPath(Agent* agent, float dTime) override;
};

