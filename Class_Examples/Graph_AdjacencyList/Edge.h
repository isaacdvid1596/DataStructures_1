#pragma once
#include "Vertex.h"
class Edge
{
public:
	Edge *next;
	Vertex *adj;
	int weight;
	void setWeight(int);
	int getWeight();
	Edge();
	~Edge();
};