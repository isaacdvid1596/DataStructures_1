#pragma once
#include <iostream>

using namespace std;

class Node
{
public:
	int key;
	Node *left;
	Node *right;
	Node();
	~Node();
};

