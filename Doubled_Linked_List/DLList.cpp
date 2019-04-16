#include "DLList.h"



DLList::DLList()
{
	head = NULL;
	tail = NULL;
}


DLList::~DLList()
{
}

void DLList::createNode(int value)
{
	node *temp = new node;
	temp->data = value;
	temp->next = NULL;
	temp->back = NULL;
	if(head==NULL)
	{
		head = temp;
		tail = temp;
		temp = NULL;
	}

	else
	{
		tail->next = temp; //assign temp memory address to element pointed by tail->next
		temp->back = tail;//assign tail memory address (former tail node) to the back pointer of new tail element temp
		tail = temp;//assign temp memory address to tail so tail now points to temp, temp is new tail
		tail->next = NULL;//tail->next now points to NULL
		
	}

}
void DLList::displayList()
{
	node *temp = new node;
	temp = head;
	while (temp != NULL)
	{
		cout << temp->data<< endl;
		temp = temp->next;
	}
}

void DLList::displayListBackwards()
{
	node *temp = new node;
	temp = tail; //assign tail memory address to temp variable

	while (temp != NULL)
	{
		cout << temp->data << endl;//print data member of tail node
		temp = temp->back;//go backwards with temp back pointer
	}
}


void DLList::insertElementStart(int value)
{
	node *temp = new node;

	temp->data = value;
	temp->next = head;
	head->back = temp;
	temp->back = NULL;
	head->back = temp;
	head = temp;
}

void DLList::insertElementEnd(int value)
{
	node *temp = new node;
	temp->data = value;
	temp->back = tail;
	tail->next = temp;
	tail = temp;
}
	
void DLList::insertElementPosition(int pos, int value)
{
	node *temp = new node; //create temp node
	node *curr = new node; //create curr node
	node *prev = new node;//create prev node

	curr = head; //assign head memory address so current points to the first element

	for (int i = 0; i < pos; i++)//go through node list until in position
	{
		prev = curr;//assign curr memory address to prev to it becomes the new prev element
		curr = curr->next;//assign curr->next memory address of next curr element to curr so it becomes new curr
	}
	temp->data = value;//assign value to temp's data member
	prev->next = temp;// assign memory address of temp to prev->next so prev points to temp;
	temp->back = prev;//assign prev memory address to temp->back so it points backwards to prev element
	curr->back = temp;//assign temp memory address to curr->node to current moved node points to temp
	temp->next = curr;//assign curr memory address to temp->next so temp points to curr and sets in new position
	//curr->next->back=temp;




}
void DLList::deleteElementEnd()
{
	node *temp = new node; //create temp node
	temp = tail; //assisgn tail memory address to temp 
	tail = temp->back;
	tail->next = NULL;

	delete temp;
}


void DLList::deleteElementStart()
{
	node *temp = new node; //create temp node
	temp = head;//assign head memory address to temp 
	head = temp->next;//head becomes the element pointed by temp->next , aka node next to head	
	head->back = NULL; //
	delete temp;
}
void DLList::deleteElementPosition(int pos)
{
	node *temp = new node;//create temp node;
	node *curr = new node;//create curr node;
	node *prev = new node;//create prev node;

	curr = head; //assign head memory address to curr 

	for (int i = 0; i < pos; i++)//go through nodes until reaching pos
	{
		prev = curr;//
		curr = curr->next;
	}

	temp = curr->next;
	prev->next = temp;
	temp->back = prev;
	delete curr;








}
