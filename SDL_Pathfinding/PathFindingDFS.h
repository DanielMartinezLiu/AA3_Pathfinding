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
	PathFindingDFS(Grid* grid, std::vector<Agent*> agent) : PathFindingAlgorithm(grid, agent) {}

	void InitFind();

	virtual void FindPath(float dTime) override;

};

