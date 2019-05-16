#pragma once
#include "Element.h"
#include <iostream>

using namespace std;


class Queue
{
public:
	Element *head;
	Element *sentinel;
	Queue();
	~Queue();
	int Enqueue(Element *element);
	int Dequeue();
	bool Empty();
	void PrintQueue();
	//void maxRep();
	//void totalTime();
};

