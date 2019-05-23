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

		

		int typeACounter = 0;


		Customer *temp = this->head;

		//if list only has an A priority
		if (temp->getpriorityTicket() =='A')
		{
			temp->next = customer;
		}
		//if list has an element that is not a on the head and the upcoming element is A
		else if (temp->getpriorityTicket() != 'A' && customer->getpriorityTicket() == 'A')
		{
			this->head = customer;
			this->head->next = temp;
		}

		//if we want to insert a Third priority [C] after 3 customers or after every A

		


		else if (customer->getpriorityTicket()=='C')
		{


			Customer *temp1 = this->head;

			int actualPos = 1;

			while (actualPos <= 3)
			{
				temp1 = temp1->next;
				actualPos++;
			}

			temp1->next = customer;
			customer = temp1->next->next;

		}

		


		

		

		








		/*
		this->tail->next = customer;
		this->tail = customer;
		customer->next = NULL;
		*/
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
		cout << "Dequeued " << customer1->getpriorityTicket() << endl;
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
			cout << customer->getpriorityTicket() << endl;
			customer = customer->next;
		}

	}
}