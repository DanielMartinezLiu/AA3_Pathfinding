#pragma once
#include <queue>
#include <unordered_map>

#include "PathFindingAlgorithm.h"
#include "Node.h"
#include "Connection.h"

class PathFindingAStar : public PathFindingAlgorithm
{
public:
	PathFindingAStar(Grid* grid) : PathFindingAlgorithm(grid) {}
	void InitFind();

	virtual void FindPath(Agent* agent, float dTime) override;
};