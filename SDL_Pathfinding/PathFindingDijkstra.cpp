#include "PathFindingDijkstra.h"

void PathFindingDijkstra::InitFind()
{
	frontier.push({ start, 0 });
	cameFrom.push_back(new Connection(start, start, 0));
	costSoFar.emplace(start, 0);
}

void PathFindingDijkstra::InitPath()
{
	current = goal;
	path.push_back(current);
}

void PathFindingDijkstra::FindPath(Agent* agent, float dTime)
{
	// Si llegas a la meta, deja de pintar mapa
	if (goalReached || frontier.empty())
		return;

	// Suma el tiempo para dibujar el mapa
	elapsedTime += dTime;

	if (elapsedTime > 0.01f)
	{
		std::pair<Node*, float> currentPair = frontier.top();
		Node* _current = currentPair.first;
		frontier.pop();

		nodes.push_back(_current);

		// Si el mapa ya se ha pintado completamente, iniciamos el camino
		if (*_current == *goal)
		{
			goalReached = true;
			InitPath();
			return;
		}

		// Comprobamos los vecinos
		for (Node* next : grid->getNeighbours(_current))
		{
			float newCost = costSoFar[_current] + grid->getCost(_current, next);
			if (costSoFar.find(next) == costSoFar.end() || newCost < costSoFar[next])
			{
				costSoFar.emplace(next, newCost);
				frontier.push({ next, newCost });
				cameFrom.push_back(new Connection(_current, next, newCost));
			}
		}
		elapsedTime = 0;
	}
}

void PathFindingDijkstra::RecoverPath(Agent* agent)
{
	if (goalReached)
	{
		if(*current != *start) 
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

void PathFindingDijkstra::resetNodes()
{
	frontier = std::priority_queue<std::pair<Node*, float>>();
	goalReached = false;
	nodes.clear();
	cameFrom.clear();
	current = nullptr;
	path.clear();
}
