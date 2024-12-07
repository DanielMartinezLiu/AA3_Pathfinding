#pragma once
#include <queue>
#include <unordered_map>
#include <memory>

#include "PathFindingAlgorithm.h"
#include "Node.h"
#include "Connection.h"

class PathFindingDijkstra : public PathFindingAlgorithm
{
private:
	std::priority_queue<std::pair<Node*, float>> frontier;
	std::vector<Connection*> cameFrom;
	std::unordered_map<Node*, int> costSoFar;
	Node* current;
	std::vector<Node*> path;

public:
	PathFindingDijkstra(Grid* grid) : PathFindingAlgorithm(grid) {}

	void InitFind();
	void InitPath();

	virtual void FindPath(Agent* agent, float dTime) override;
	virtual void RecoverPath(Agent* agent) override;
	virtual void resetNodes() override;
};

