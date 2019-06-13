#pragma once
#include <iostream>
#include <string>
#include "Vertex.h"
#include "Edge.h"

using namespace std;

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
	void DeleteEdge(Vertex *origin, Vertex *destiny);
	void Nullify();
	~Graph();
};