#pragma once
#include "Bread.h"

class StackBread
{
private:
	int counter;
	void increaseCounter();
	void decreaseCounter();
public:

	Bread *head;
	Bread *tail;
	StackBread();
	~StackBread();
	bool Empty();
	int Push(Bread *bread);
	int Pop();
	void Print();
};

