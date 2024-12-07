#pragma once

#include <queue>
#include <unordered_map>

#include "Agent.h"
#include "Grid.h"
#include "Connection.h"

struct PriorityQueueComparator {
	bool operator()(const std::pair<Node*, int>& a, const std::pair<Node*, int>& b) const {
		return a.second > b.second;
	}
};

class PathFindingAlgorithm
{

protected:
	std::priority_queue<std::pair<Node*, int>, std::vector<std::pair<Node*, int>>, PriorityQueueComparator> frontierQueuePriority;
	std::queue<Node*> frontierQueue;
	std::vector<Connection*> cameFrom;
	std::unordered_map<Node*, int> costSoFar;
	Node* current;
	std::vector<Node*> path;

	Node* start;
	Node* goal;
	Grid* grid;

	float elapsedTime;
	std::vector<Node*> nodes;
	bool goalReached;

public:
	PathFindingAlgorithm(Grid* _grid);

	void InitPath();

	virtual void FindPath(Agent* agent, float dTime);
	void RecoverPath(Agent* agent);

	void resetNodes();
	void draw();


	void setStart(Node* _start) { start = _start; }
	void setGoal(Node* _goal) { goal = _goal; }
	void setGrid(Grid* _grid) { grid = _grid; }
};