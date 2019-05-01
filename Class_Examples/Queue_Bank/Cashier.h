#pragma once
#include <iostream>
#include "Customer.h"

using namespace std;

class Cashier
{
private:
	int counter;
	void increaseCounter();
	void decreaseCounter();


public:
	Cashier();
	virtual ~Cashier();
	Customer *head;
	Customer *tail;
	int Enqueue(Customer *customer);
	int Dequeue(Customer *customer);
	int getCounter();
	bool Empty();
	void printQueue();
};

