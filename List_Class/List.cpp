#include "List.h"



List::List()
{
	head = NULL;
	tail = NULL;
}

List::~List()
{

}

void List:: createNode(int value)
{
	node * temp = new node; //create new node
	temp->data = value; //assign value to temp's data member
	temp->next = NULL;//assign temp's next pointer , pointing to NULL (0)
	if (head == NULL) //if head is pointing to nothing then
	{
		head = temp; //assign temp memory address to head;
		tail = temp;//assign temp memory address to tail;
		temp = NULL;//assign NULL location to temp, temp pointing to NULL
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}


void List::displayList()
{
	node *temp = new node; //create new node

	temp = head; //assign head pointer to temp variable

	while (temp != NULL) //print the data inside of temp variable while head is pointing something
	{
		cout << temp->data << endl;
		temp = temp->next;//assign temp variable location to next element,which will become next temp,etc.
	}



}

void List::insertElementStart(int value)
{
	node *temp = new node;//create new node
	temp->data = value; //assign value to temp's data member
	temp->next = head; //assign former head memory address to node next to temp
	head = temp;//assign temp memory address to head


}

void List::insertElementEnd(int value)
{
	node *temp = new node; //create new element 

	temp->data = value;//assign value to temp's data member

	tail->next = temp;//assign temp memory address to new element 
	tail = temp;

}
void List::insertElementPosition(int pos,int value)
{
	node * prev = new node; //create new element , previous position
	node * curr = new node;// create new element , current position
	node * temp = new node;//create new element , temp
	curr = head;//assign head memory address to current 

	for (int i = 0; i < pos; i++)
	{
		prev = curr;
		curr = curr->next;
	}

	temp->data = value;
	prev->next = temp;
	temp->next=curr;

}

void List::deleteElementEnd()
{
	node * curr = new node; //create current temporary pointer
	node * prev = new node;//create previous temporary pointer
	curr = head; //assign head memory address to curr; 
	
	while (curr->next != NULL) //while there is an element next to current one
	{
		prev = curr; //assign current memory address to previous
		curr = curr->next;//assign current->next memory address to current, now pointing to new one
	}

	tail = prev;//assuming that a step before current=tail,now we assign prev memory address to tail
	prev->next = NULL;//we nullify whats next after previous pointer(former current)
	delete curr;//delete current from memory


}


void List::deleteElementStart()
{
	node * temp = new node; //create new temp node
	temp = head; //assign head memory address to temp variable
	head=head->next;//assign memory address of next element head was pointing to the current head
	delete temp; //delete temp variable
}

void List::deleteElementPosition(int pos)
{
	node *curr = new node; //create curr pointer node

	node *prev = new node;//create prev pointer node

	curr = head; //assign head memory address to curr

	for (int i = 0; i < pos; i++) //go through the list until desired position is reached
	{
		prev = curr; //assign curr address to prev pointer
		curr = curr->next;//assign address of element pointed by curr->next to the curr pointer
	}

	prev->next = curr->next;//assign adress of element pointer by curr to element pointed by prev element 
}






