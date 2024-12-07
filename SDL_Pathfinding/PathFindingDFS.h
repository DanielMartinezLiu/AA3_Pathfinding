#pragma once
#include <queue>
#include <map>
#include <memory>

#include "PathFindingAlgorithm.h"
#include "Node.h"
#include "Connection.h"

class PathFindingDFS : public PathFindingAlgorithm
{
private:
	std::queue<Node*> frontier;
	std::vector<Connection*> cameFrom;
	//std::map<Node*, Connection*> cameFrom;
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

