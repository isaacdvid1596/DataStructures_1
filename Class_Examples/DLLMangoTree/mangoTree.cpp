#include "mangoTree.h"



mangoTree::mangoTree()
{
	this->head = NULL;
	this->tail = NULL;
	this->counter = 0;
}


mangoTree::~mangoTree()
{
}


int mangoTree::addMango(mangoFruit *mango)
{
	if (this->head == 0)
	{
		this->head = mango;
		this->tail = mango;
	}
	else
	{
		this->tail->next = mango;
		mango->prev = this->tail;
		this->tail = mango;
	}
	
	increaseCounter();
	return 0;

}

int mangoTree::insertMango(mangoFruit *mango, int pos)
{
	if (pos > this->getCounter() + 1)
	{
		return -1;
	}
	else if (pos < 0)
	{
		return -2;
	}

	else if (pos == this->getCounter() + 1)
	{
		this->addMango(mango);
		return 0;
	}
	else if (pos <= this->getCounter())
	{
		mangoFruit *temp = this->head;
		int actualPos = 1;
		while (actualPos < pos)
		{
			actualPos++;
			temp = temp->next;
		}
		mango->prev = temp->prev;
		mango->next = temp;
		mango->prev->next = mango;
		temp->prev = mango;
		increaseCounter();
		return 0;
	}
	return -3;
}

int mangoTree::deleteMango(int pos)
{
	if (pos > this->getCounter())
	{
		return -1;
	}

	else if (pos < 0)
	{
		return -2;
	}

	else if (pos <= this->getCounter())
	{
		mangoFruit *temp = this->head;
		int actualPos = 1;

		while (actualPos < pos)
		{
			actualPos++;
			temp = temp->next;
		}

		if (temp == this->head)
		{
			temp->next->prev = nullptr;
			head = head->next;
		}
		else if (temp == this->tail)
		{
			temp->prev->next = NULL;
			tail = tail->prev;
		}
		else
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
		}

		delete temp;
		decreaseCounter();
		return 0;

	}
}

void mangoTree::printMangoTree()
{

}

int mangoTree::getCounter()
{
	return this->counter;
}

void mangoTree::increaseCounter()
{
	this->counter++;
}

void mangoTree::decreaseCounter()
{
	this->counter--;
}