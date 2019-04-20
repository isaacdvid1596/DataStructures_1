#include "Stack.h"



Stack::Stack()
{
	stackPtr = NULL;
}


Stack::~Stack() //called when stackptr is about to be destroyed
{
	node *p1; //create p1 node
	node *p2;//create p2 node

	p1 = stackPtr; //assisgn memory address of stackPtr to p1, p1 now pointing to same element as stackPtr

	while (p1 != NULL)
	{
		p2 = p1; //assign memory address of p1 to p2
		p1 = p1->prev;// assign memory address of element previous to p1 (p1->prev) to p1
		p2->prev = NULL;//assign memory adress NULL to element before p2;
		delete p2; //delete p2;
	}
}


void Stack::Push(string name, int value)
{
	node * temp = new node; //create new temp node
	temp->name = name;//initialize name temp member
	temp->value = value;//initialize value temp member

	if (stackPtr == NULL) // if stackptr is pointing at nothing
	{
		stackPtr = temp; //assign temp memory address to stackPtr
		stackPtr->prev = NULL; // assign a null memory address to Stackptr's prev pointer
	}
	else //if stackPtr is currently pointing at something then
	{
		temp->prev = stackPtr; //assign stackPtr memory address to temp->prev
		stackPtr = temp; //assign temp memory address to stackPtr;
	}

}
void Stack::Pop()
{
	if (stackPtr == NULL)
	{
		cout << "Stack empty" << endl;
	}
	else
	{
		node * temp = new node; //create new temp node
		temp = stackPtr; //assign memory stackptr memory address to temp 
		readItem(temp);//readItem function                      //also can stackptr=stackptr->prev / temp->NULL
		stackPtr = temp->prev;//assign temp->prev memory address to stackptr so now it points to element below former stack top		delete temp;
	}
	
}
void Stack::readItem(node *read)
{
	cout << "---------------------\n";
	cout << "Name: " << read->name << endl;
	cout << "Value: " << read->value << endl;
	cout << "---------------------\n";

}
void Stack::Print()
{
	node *temp = new node;

	temp = stackPtr;
	if (stackPtr == NULL)
	{
		cout << "no items on stack" << endl;
	}

	else
	{

		while (temp != NULL) //while temp is pointing to something
		{
			readItem(temp); //readItem pass temp as parameter 
			temp = temp->prev; //assign temp->prev memory address to temp so it goes through nodes until it points to NULL

		}

	}

}