#include "Graph.h"
#include "Edge.h"
#include "Vertex.h"


Graph::Graph()
{
	this->h = NULL;
}


Graph::~Graph()
{

}

bool Graph::Empty()
{
	if (this->h == NULL)
	{
		return true;
	}
	else
		false;
}

int Graph::SizeOfGraph()
{
	int count = 0;
	Vertex *temp = this->h;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}

	return count;
}

Vertex *Graph::getVertex(string name)
{
	Vertex *temp = this->h;
	while (temp != NULL)
	{
		if (temp->name == name)
		{
			return temp;
		}
		else
			return nullptr;
		temp = temp->next;
	}
}

void Graph::addVertex(string name)
{
	Vertex *newVertex = new Vertex;
	newVertex->name = name;
	newVertex->next = NULL;
	newVertex->adj = NULL;

	if (Empty() == true)
	{
		this->h = newVertex;
	}
	else
	{
		Vertex *temp = this->h;
		while (temp != NULL)
		{
			temp = temp->next;
		}
		temp->next = newVertex;
	}
}

void Graph::addEdge(Vertex *origin, Vertex* destiny, int weight)
{
	Edge *newEdge = new Edge;
	newEdge->weight = weight;
	newEdge->next = NULL;
	newEdge->adj = NULL;

	Edge *temp;
	temp = origin->adj;

	if (temp == NULL)
	{
		origin->adj = newEdge;
		newEdge->adj = destiny; 
	}
	else
	{
		while (temp->next != NULL)
		{
			temp =temp->next
		}
		temp->next = newEdge;
		newEdge->adj = destiny;
	}

}



void AdjList()
{

}

