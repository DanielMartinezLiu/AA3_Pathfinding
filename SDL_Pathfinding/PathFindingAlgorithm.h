#pragma once

// Referencia cruzada con agent, pero lo pide el profe asi en el UML
#include "Agent.h"

class PathFindingAlgorithm
{
public:
	PathFindingAlgorithm() {}
	virtual void FindPath(Agent* agent, float dTime);
};