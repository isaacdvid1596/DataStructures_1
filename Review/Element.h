#pragma once
#include <iostream>

using namespace std;

class Element
{
public:
	Element *next;
	int optType;
	int aproxTime;
	Element();
	Element(int,int);
	~Element();
	void setOperation(int operation);
	int getOperation();
	void setTime(int time);
	int getTime();
};

