#include "PathFindingAlgorithm.h"

PathFindingAlgorithm::PathFindingAlgorithm(Grid* _grid)
{
	start = nullptr;
	goal = nullptr;
	elapsedTime = 0;
	goalReached = false;
	grid = _grid;
}

void PathFindingAlgorithm::FindPath(Agent* agent, float dTime)
{
}

void PathFindingAlgorithm::resetNodes()
{

}

void PathFindingAlgorithm::RecoverPath(Agent* agent)
{
}

void PathFindingAlgorithm::draw()
{
	for (Node* node : nodes)
	{
		Vector2D position = grid->cell2pix(Vector2D(node->getX(), node->getY()));
		node->draw(position);
	}
}
