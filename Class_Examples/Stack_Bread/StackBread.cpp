#include "StackBread.h"



StackBread::StackBread()
{
	
}


StackBread::~StackBread()
{

}

bool StackBread::Empty()
{
	if ((this->head && this->tail) == NULL)
	{
		return true;
	}
	else
		return false;
}


int StackBread::Push(Bread *bread)
{
	if (Empty() == true)
	{
		this->head = bread;
		this->tail = bread;
		bread->next = NULL;
	}
	else
	{
		bread->next = head;
		this->head = bread;
		this->tail = bread->next;
	}

	return 1;

	increaseCounter();

}

int StackBread::Pop()
{

	if (Empty() == true)
	{
		cout << "Stack empty cannot pop" << endl;
	}
	else
	{
		Bread *bread = new Bread;

		bread = this->head;
		this->head = bread->next;
		cout << "Popping " << bread->getWeight() << endl;
		delete bread;

	}

	return 2;

	decreaseCounter();

}

void StackBread::Print()
{
	if (Empty() == true)
	{
		cout << "Stack empty cannot print" << endl;
	}
	else
	{
		Bread *bread = new Bread;
		bread = this->head;
		while (bread != NULL)
		{
			cout << bread->getWeight() << endl;
			bread = bread->next;
		}
	}
}

void StackBread::increaseCounter()
{
	counter++;
}

void StackBread::decreaseCounter()
{
	counter--;
}
