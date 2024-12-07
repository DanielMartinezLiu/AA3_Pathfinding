#pragma once
#include <queue>
#include <unordered_map>
#include "PathFindingAlgorithm.h"
#include "Node.h"

class PathFindingDFS : public PathFindingAlgorithm
{
private:
	std::queue<Node*> frontier;
	std::unordered_map<Node*, Node*> cameFrom;
	Node* current;
	std::vector<Node*> path;

public:
	PathFindingDFS(Grid* grid) : PathFindingAlgorithm(grid) {}

	void InitFind();
	void InitPath();

	virtual void FindPath(Agent* agent, float dTime) override;
	virtual void RecoverPath(Agent* agent) override;
	virtual void resetNodes() override;

};

