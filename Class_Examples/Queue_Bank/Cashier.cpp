#include "Cashier.h"



Cashier::Cashier()
{

}


Cashier::~Cashier()
{

}

int Cashier::Enqueue(Customer *customer)
{
	if (Empty()==true)
	{
		this->head = customer;
		this->tail = customer;
	}
	else
	{
		this->tail->next = customer;
		this->tail = customer;
		customer->next = NULL;
	}
}

int Cashier::Dequeue(Customer *customer)
{

}

bool Cashier::Empty()
{
	if (this->counter == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Cashier::getCounter()
{
	return this->counter;
}

void Cashier::increaseCounter()
{
	this->counter++;
}

void Cashier::decreaseCounter()
{
	this->counter--;
}

void Cashier::printQueue()
{

}