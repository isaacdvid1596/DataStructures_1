#include "Queue.h"



Queue::Queue()
{
	this->head = sentinel;
	this->sentinel->next = sentinel;
}



Queue::~Queue()
{

}

int Queue::Enqueue(Element *element)
{
	if (Empty() == true)
	{
		this->head=element;
		element->next = sentinel;
	}
	else
	{
		Element *temp = this->head;
		Element *temp1 = temp;
		while(temp->getOperation()!=100)
		{
			temp1 = temp;
			temp = temp->next;
		}
		temp1->next = element;
		element->next = temp;
	}

	return 50;
}

int Queue::Dequeue()
{
	if (Empty() == true)
	{
		cout << "Queue Empty" << endl;
	}
	else
	{
		Element *temp = head;
		this->head = temp->next;
		delete temp;
	}

	return 20;
}

bool Queue::Empty()
{
	if (this->head = sentinel)
	{
		return true;
	}
	else
		return false;
}

void Queue::PrintQueue()
{
	Element *temp = head;
	while (temp != sentinel)
	{
		cout << temp->getOperation() << endl;
		cout << temp->getTime() << endl;
		temp = temp->next;
	}
}


