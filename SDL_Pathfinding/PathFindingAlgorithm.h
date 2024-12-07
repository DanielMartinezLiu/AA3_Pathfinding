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

	virtual void FindPath(Agent* agent, float dTime) = 0;
	virtual void InitFind() = 0;

	void RecoverPath(Agent* agent);

	void ExecuteAlgorithm(Node* _startNode, Node* _goalNode);

	void ResetNodes();
	void Draw();

	void Update(Agent* _agent, float dt);


	void SetStart(Node* _start) { start = _start; }
	void SetGoal(Node* _goal) { goal = _goal; }
	void SetGrid(Grid* _grid) { grid = _grid; }
};