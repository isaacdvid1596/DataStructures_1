#pragma once
#include <iostream>

using namespace std;	

struct node
{
	int data;
	node *next;
};

class Queues
{

private:
	node *front;
	node *rear;
public:
	Queues();
	virtual ~Queues();
	void Enqueue(int data);
	void Dequeue();
	void readItem(node *read);
	void Print();

	
};