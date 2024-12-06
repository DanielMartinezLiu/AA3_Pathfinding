#include "PathFindingAlgorithm.h"

PathFindingAlgorithm::PathFindingAlgorithm(Grid* _grid)
{
	start = new Node(0, 0, 0);
	goal = new Node(0, 0, 0);

	grid = _grid;
}

void PathFindingAlgorithm::FindPath(Agent* agent, float dTime)
{
}

void PathFindingAlgorithm::resetNodes()
{
	nodes.clear();
}

void PathFindingAlgorithm::draw()
{
	for (Node* node : nodes)
	{
		Vector2D position = grid->cell2pix(Vector2D(node->getX(), node->getY()));
		node->draw(position);
	}
}
