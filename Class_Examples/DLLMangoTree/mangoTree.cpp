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

	increaseFruit();

	increaseCounter();
	return 5;


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

		if (actualPos == pos)
		{

			mango->prev = NULL;
			mango->next = temp;
			temp->prev = mango;
			this->head = mango;
		}
		else
		{
			mango->prev = temp->prev;
			mango->next = temp;
			mango->prev->next = mango;
			temp->prev = mango;
		}



		increaseCounter();
		return 0;
	}
	increaseFruit();
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
			if (temp->next)
			{
				temp->next->prev = nullptr;
			}

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
		

	}

	decreaseFruit();
	return 0;
}

void mangoTree::printMangoTree()
{
	mangoFruit *temp = new mangoFruit;
	temp = this->head;

	while (temp != NULL)
	{
		cout << temp->getWeight() << endl;
		temp = temp->next;
	}
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

double mangoTree::getTotalWeight()
{
	double totalWeight = 0.0;

	mangoFruit *mango = new mangoFruit;
	mango = this->head;

	while (mango != NULL)
	{
		totalWeight += mango->getWeight();
		mango = mango->next;
	}

	cout << totalWeight << endl;

	return totalWeight;

}

int mangoTree::getFruitQuantity()
{
	cout << this->fruitCounter << endl;
	return fruitCounter;
}


bool mangoTree::fruitMaxCapacityExceeded()
{
	int maxCapacity = 50;

	if (this->getCounter() > maxCapacity)
	{
		return true;
	}
	else
		return false;

}

bool mangoTree::treeMaxWeightExceeded()
{
	double maxWeight = 500.00;

	if (this->getTotalWeight() > maxWeight)
	{
		return true;
	}
	else
		return false;

}

int mangoTree::sortMangoTree()
{
	mangoFruit *temp = this->head;
	mangoFruit *temp1 = this->head->next;
	mangoFruit *temp2 = this->head;


	for (int i = 0; i <= fruitCounter; i++)
	{
		if (temp->getWeight() > temp1->getWeight())
		{
			temp->next = temp1->next;
			temp1->next->prev = temp;
			temp->prev = temp1;
			temp1->next = temp;
			this->head = temp1;

			temp = temp->next;
			temp1 = temp;

		}

		
	}

	printMangoTree();

	/*
		if (temp->getWeight() > temp1->getWeight())
		{
			temp->next = temp1->next;
			temp1->next->prev = temp;
			temp->prev = temp1;
			temp1->next = temp;
			this->head = temp1;
		}
		*/

	return 3000;
}

void mangoTree::decreaseFruit()
{
	this->fruitCounter--;
}

void mangoTree::increaseFruit()
{
	this->fruitCounter++;
}