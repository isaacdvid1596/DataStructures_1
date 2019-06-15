#pragma once
#include <iostream> 
class Element
{
public:
	int key;
	Element *left;
	Element *right;
	Element();
	~Element();
};

