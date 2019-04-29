#pragma once
#include <iostream>

using namespace std;



class mangoFruit
{

private:
	double weight;

public:

	mangoFruit *next;
	mangoFruit *prev;
	mangoFruit();
	mangoFruit(double);
	virtual ~mangoFruit();
	void setWeight(double);
	double getWeight();

};

