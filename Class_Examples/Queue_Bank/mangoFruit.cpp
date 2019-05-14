#include "mangoFruit.h"



mangoFruit::mangoFruit()
{
	setWeight(0);
	this->next = NULL;
	this->prev = NULL;
}


mangoFruit::mangoFruit(double w)
{
	setWeight(w);
	this->next = nullptr;
	this->prev = nullptr;

}

mangoFruit::~mangoFruit()
{

}

void mangoFruit::setWeight(double w)
{
	this->weight = w - (0.1*w);
}

double mangoFruit::getWeight()
{
	return this->weight;
}