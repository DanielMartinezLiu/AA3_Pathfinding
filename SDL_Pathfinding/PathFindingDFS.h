#pragma once

#include "PathFindingAlgorithm.h"

class PathFindingDFS : public PathFindingAlgorithm
{
public:
	virtual void FindPath(Agent* agent, float dTime) override;
};

