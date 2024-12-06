#pragma once
#include <queue>
#include <unordered_map>
#include "PathFindingAlgorithm.h"
#include "Node.h"

class PathFindingDFS : public PathFindingAlgorithm
{
private:
	std::queue<Node*> frontier;
	std::unordered_map<Node*, bool> visited;

public:
	PathFindingDFS(Grid* grid) : PathFindingAlgorithm(grid) {}

	void InitFind();

	virtual void FindPath(Agent* agent, float dTime) override;

};

