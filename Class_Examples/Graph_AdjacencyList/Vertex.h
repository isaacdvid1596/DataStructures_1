#pragma once
#include <iostream>

using namespace std;
class Vertex
{
public:
	Vertex *next;
	Edge *adj;
	string name;
	Vertex();
	~Vertex();
};

