#pragma once
#include <iostream>
#include "mangoFruit.h"

class mangoTree
{

private:
	//int fruitCounter = 0;
	//void decreaseFruit();
	//void increaseFruit();
	int counter;
	void increaseCounter();
	void decreaseCounter();

public:
	mangoFruit *head;
	mangoFruit *tail;
	mangoTree();
	virtual ~mangoTree();
	int addMango(mangoFruit *mango);
	int insertMango(mangoFruit *mango, int pos);
	int deleteMango(int pos);
	int getCounter();
	void printMangoTree();
	int sortMangoTree();
	int getFruitQuantity();
	double getTotalWeight();
	bool fruitMaxCapacityExceeded();
	bool treeMaxWeightExceeded();
	int fruitCounter = 0;
	void decreaseFruit();
	void increaseFruit();



};
