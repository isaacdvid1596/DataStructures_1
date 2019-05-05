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

	return 1;

	

}



int Cashier::Dequeue(Customer *customer)
{
	if (Empty() == true)
	{
		cout << "Queue is empty , cannot dequeue" << endl;
	}
	else
	{
		Customer *customer1 = new Customer;
		customer1 = this->head;
		head = customer1->next;
		cout << "Dequeued " << customer1->getTicketNumber() << endl;
		delete customer1;
	}

	return 2;

	increaseCounter();
}

bool Cashier::Empty()
{
	if ((this->head && this->tail) == NULL)
	{
		return true;
	}
	else
	{
		false;
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
	if (Empty()==true)
	{
		cout << "Empty queue , cannot print" << endl;
	}
	else
	{
		Customer *customer = new Customer;
		customer = head;
		while (customer != NULL)
		{
			cout << customer->getTicketNumber() << endl;
			customer = customer->next;
		}

	}
}