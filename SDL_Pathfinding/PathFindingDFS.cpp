#include "PathFindingDFS.h"
#include <queue>
#include <unordered_map>
#include "Node.h"

void PathFindingDFS::FindPath(Agent* agent, float dTime)
{

	std::queue<Node*> frontier;
	frontier.push(start);

	std::unordered_map<Node*, bool> visited;
	visited[start] = true;

	while (!frontier.empty())
	{
		Node* current = frontier.front();
		frontier.pop();

		if (*current == *goal)
			break;

		for (Node* next : grid->getNeighbours(current))
		{
			if (visited.find(next) == visited.end())
			{
				frontier.push(next);
				nodes.push_back(next);
				visited[next] = true;
			}
		}
	}
}
