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

	return 0;

}



int Cashier::Dequeue(Customer *customer)
{
	if (Empty() == true)
	{
		cout << "Queue is empty , cannot dequeue" << endl;
	}
	else
	{
		customer = this->head;
		this->head = customer->next;
		delete customer;
	}
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