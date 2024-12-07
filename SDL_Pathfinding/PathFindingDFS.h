#pragma once
#include <queue>
#include <map>
#include <memory>

#include "PathFindingAlgorithm.h"
#include "Node.h"
#include "Connection.h"

class PathFindingDFS : public PathFindingAlgorithm
{

public:
	PathFindingDFS(Grid* grid) : PathFindingAlgorithm(grid) {}

	void InitFind();

	virtual void FindPath(Agent* agent, float dTime) override;

};

