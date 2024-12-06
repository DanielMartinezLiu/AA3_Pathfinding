#include "PathFindingDFS.h"

void PathFindingDFS::InitFind()
{
	frontier.push(start);
	visited[start] = true;
}

void PathFindingDFS::FindPath(Agent* agent, float dTime)
{
	if (goalReached || frontier.empty())
		return;
	
	elapsedTime += dTime;

	if (elapsedTime > 0.01f)
	{
		Node* current = frontier.front();
		frontier.pop();

		nodes.push_back(current);

		if (*current == *goal)
		{
			goalReached = true;
			return;
		}

		for (Node* next : grid->getNeighbours(current))
		{
			if (visited.find(next) == visited.end())
			{
				frontier.push(next);
				visited[next] = true;
			}
		}
		elapsedTime = 0;
	}
}
