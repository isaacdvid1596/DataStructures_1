#pragma once
#include <iostream>

using namespace std;
class Vertex
{
public:
	Vertex *next;
	Edge *adj;
	string name;
	void setName(string);
	string getName();
	Vertex();
	~Vertex();
};