#pragma once

#include "PathFindingAlgorithm.h"

class PathFindingAStar : public PathFindingAlgorithm
{
public:
	virtual void FindPath(Agent* agent, float dTime) override;
};

