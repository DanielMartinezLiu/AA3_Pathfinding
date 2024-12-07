#include "PathFindingAlgorithm.h"

PathFindingAlgorithm::PathFindingAlgorithm(Grid* _grid)
{
	start = nullptr;
	goal = nullptr;
	elapsedTime = 0;
	goalReached = false;
	grid = _grid;
}

void PathFindingAlgorithm::InitPath()
{
	current = goal;
	path.push_back(current);
}

void PathFindingAlgorithm::FindPath(Agent* agent, float dTime)
{
}

void PathFindingAlgorithm::resetNodes()
{
	frontierQueue = std::queue<Node*>();
	frontierQueuePriority = std::priority_queue<std::pair<Node*, int>, std::vector<std::pair<Node*, int>>, PriorityQueueComparator>();
	goalReached = false;
	nodes.clear();
	cameFrom.clear();
	current = nullptr;
	path.clear();
	costSoFar.clear();
}

void PathFindingAlgorithm::RecoverPath(Agent* agent)
{
	if (goalReached)
	{
		if (*current != *start)
		{
			// Miramos el path del goal -> start 
			for (Connection* conn : cameFrom)
			{
				// Si el connection actual es igual al current, añadimos un nuevo valor al path para el Agent
				if (*conn->getNodeTo() == *current)
				{
					path.push_back(conn->getNodeTo());
					current = conn->getNodeFrom();
					break;
				}
			}
		}
		else
		{
			std::reverse(path.begin(), path.end());

			// Mueve el agente con las posiciones por pixeles del mapa
			for (Node* node : path)
			{
				Vector2D cellPosition = grid->cell2pix(Vector2D(node->getX(), node->getY()));
				agent->addPathPoint(cellPosition);
			}

			path.clear();
		}
	}
}

void PathFindingAlgorithm::draw()
{
	for (Node* node : nodes)
	{
		Vector2D position = grid->cell2pix(Vector2D(node->getX(), node->getY()));
		node->draw(position);
	}
}
