#pragma once
#include <queue>
#include <unordered_map>
#include <memory>

#include "PathFindingAlgorithm.h"
#include "Node.h"
#include "Connection.h"


class PathFindingDijkstra : public PathFindingAlgorithm
{
public:
	PathFindingDijkstra(Grid* grid) : PathFindingAlgorithm(grid) {}

	void InitFind();

	virtual void FindPath(Agent* agent, float dTime) override;
};



