#include "PathFindingDFS.h"
#include <queue>
#include <unordered_map>
#include "Node.h"

void PathFindingDFS::FindPath(Agent* agent, float dTime)
{
	std::queue<Node*> frontier;

	Node* start = new Node(agent->getPosition().x, agent->getPosition().y);

	frontier.push(start);

	std::unordered_map<Node*, bool> reached;
	reached[start] = true;

	while (!frontier.empty())
	{
		Node* currentNode = frontier.front();
		frontier.pop();

		for (Node* next : graph.neighbors(currentNode)) {
			if (reached.find(next) == reached.end()) {
				frontier.push(next);
				reached[next] = true;
			}
		}
	}

}
