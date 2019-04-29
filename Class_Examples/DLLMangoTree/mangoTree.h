#pragma once
#include <iostream>
#include "mangoFruit.h"

class mangoTree
{

private:
	int counter;
	void increaseCounter();
	void decreaseCounter();

public:
	mangoFruit *head;
	mangoFruit *tail;
	mangoTree();
	virtual ~mangoTree();
	int addMango(mangoFruit mango);
	int insertMango(mangoFruit mango, int pos);
	int deleteMango(int pos);
	int getCounter();
	void printMangoTree();
	


};

