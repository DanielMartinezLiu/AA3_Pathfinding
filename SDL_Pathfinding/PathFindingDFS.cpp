#include "PathFindingDFS.h"

void PathFindingDFS::InitFind()
{
	frontier.push(start);
	cameFrom[start] = nullptr;
}

void PathFindingDFS::InitPath()
{
	current = goal;
	path.push_back(current);
}


void PathFindingDFS::FindPath(Agent* agent, float dTime)
{
	if (goalReached || frontier.empty())
		return;
	
	elapsedTime += dTime;

	if (elapsedTime > 0.01f)
	{
		Node* _current = frontier.front();
		frontier.pop();

		nodes.push_back(_current);

		if (*_current == *goal)
		{
			goalReached = true;
			InitPath();
			return;
		}

		for (Node* next : grid->getNeighbours(_current))
		{
			if (cameFrom.find(next) == cameFrom.end())
			{
				frontier.push(next);
				cameFrom[next] = _current;
			}
		}
		elapsedTime = 0;
	}
}

void PathFindingDFS::RecoverPath(Agent* agent)
{
	if (goalReached)
	{
		if(*current != *start) {
			std::cout << cameFrom[current];
			current = cameFrom[current];
			path.push_back(current);
		}
		else
		{
			std::reverse(path.begin(), path.end());

			for (Node* node : path) {
				Vector2D cellPosition = grid->cell2pix(Vector2D(node->getX(), node->getY()));
				agent->addPathPoint(cellPosition);
			}
			goalReached = false;
		}
	}
}

void PathFindingDFS::resetNodes()
{
	frontier = std::queue<Node*>();
	goalReached = false;
	nodes.clear();
	cameFrom.clear();
	current = nullptr;
	path.clear();
}
