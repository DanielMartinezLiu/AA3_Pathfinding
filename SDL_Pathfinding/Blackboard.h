#pragma once

#include <unordered_map>
#include <string>
#include "PathFindingGraph.h"
#include "Vector2D.h"

class Blackboard
{
private:
	std::unordered_map<std::string, void*> theBlackboard;
	PathFindingGraph* graph;

public:
	void SetFloat(std::string _key, float _value);
	float GetFloat(std::string _key);

	void SetInt(std::string _key, int _value);
	int GetInt(std::string _key);

	void SetVector2D(std::string _key, Vector2D _value);
	Vector2D GetVector2D(std::string _key);

	void SetGraphPtr(PathFindingGraph* _graph);
	PathFindingGraph GetGraph();
};