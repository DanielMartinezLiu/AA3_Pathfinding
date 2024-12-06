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
			Vector2D position = grid->cell2pix(Vector2D(next->getX(), next->getY()));
			draw_circle(TheApp::Instance()->getRenderer(), position.x, position.y, 15, 255, 255, 0, 255);

			if (visited.find(next) == visited.end())
			{
				frontier.push(next);
				visited[next] = true;
			}
		}
	}
}
