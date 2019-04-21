#include "Queues.h"



Queues::Queues()
{
	front = NULL;
	rear = NULL;
}


Queues::~Queues()
{

}

void Queues::Enqueue(int data)
{
	node * temp = new node;
	temp->data = data;

	if ((front && rear) == NULL)
	{
		front = temp;
		rear = temp;
		temp = NULL;
	}
	else
	{
		rear->next = temp;
		rear = temp;
		temp->next = NULL;
	}
}
void Queues::Dequeue()
{
	node *temp = new node;
	

	if ((front&&rear) == NULL)
	{
		cout << "emtpy queue" << endl;
	}
	else
	{
		temp = front;
		cout << "Dequeing : " <<temp->data<< endl;
		front = temp->next;
		temp->next = NULL;
		delete temp;
	}

}
void Queues::readItem(node *read)
{
	cout << "---------------------\n";
	cout << "Value: " << read->data << endl;
	cout << "---------------------\n";
}
void Queues::Print()
{

	node *temp = new node;

	temp = front;

	if ((front&&rear) == NULL)
	{
		cout << "emtpy queue" << endl;
	}
	else
	{
		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
}