#pragma once
#include "Vertex.h"
class Graph
{
public:
	Vertex *h;
	Graph();
	bool Empty();
	int SizeOfGraph();
	Vertex *getVertex(string name);
	void addEdge(Vertex *origin, Vertex* destiny, int weight);
	void addVertex(string name);
	void AdjList();
	~Graph();
};

