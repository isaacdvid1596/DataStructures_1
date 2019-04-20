#pragma once
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Stack
{

private:

	struct node
	{
		int value;
		string name;
		node *prev;
	};

	node *stackPtr;

public:
	Stack();
	~Stack();
	void Push(string name, int value);
	void Pop();
	void readItem(node *read);
	void Print();

};

