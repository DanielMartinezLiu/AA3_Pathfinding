#pragma once

#include "Connection.h"
#include <vector>

class PathFindingGraph
{
public:
	std::vector<Connection*> connections;

	PathFindingGraph(std::vector<Connection*> _connections)
		:connections(_connections){}

    void addConnection(Connection* connection) {
        connections.push_back(connection);
    }

    const std::vector<Connection*>& getConnections() const { return connections; }
};