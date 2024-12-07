#include "PathFindingGreedyBFS.h"

void PathFindingGreedyBFS::InitFind()
{
	frontier.push({ start, grid->getCost(goal, start) });
	cameFrom.push_back(new Connection(start, start, 0));
}

void PathFindingGreedyBFS::InitPath()
{
	current = goal;
	path.push_back(current);
}

void PathFindingGreedyBFS::FindPath(Agent* agent, float dTime)
{
	// Si llegas a la meta, deja de pintar mapa
	if (goalReached || frontier.empty())
		return;

	// Suma el tiempo para dibujar el mapa
	elapsedTime += dTime;

	if (elapsedTime > 0.01f)
	{
		Node* _current = frontier.top().first;
		frontier.pop();

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
			bool alreadyVisited = false;
			for (Connection* conn : cameFrom)
			{
				// Comprobamos que connection, la siguiente sea el next
				if (conn->getNodeTo() == next)
				{
					alreadyVisited = true;
					break;
				}
			}

			// Si no lo hemos visitado, añadimos un nuevo connection con el valor actual y el siguiente
			if (!alreadyVisited)
			{
				nodes.push_back(_current);
				std::cout << "Nodo Añadido: X -> " << next->getX() << " Y -> " << next->getY() << " Type -> " << next->getType() << std::endl;
				int priority = grid->getCost(goal, next); // Solo usamos la heurística
				frontier.push({ next, priority });
				cameFrom.push_back(new Connection(_current, next, 0));
			}
		}
		elapsedTime = 0;
	}
}

void PathFindingGreedyBFS::RecoverPath(Agent* agent)
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

void PathFindingGreedyBFS::resetNodes()
{
	frontier = std::priority_queue<std::pair<Node*, int>, std::vector<std::pair<Node*, int>>, PriorityQueueComparator>();
	goalReached = false;
	nodes.clear();
	cameFrom.clear();
	current = nullptr;
	path.clear();
}
