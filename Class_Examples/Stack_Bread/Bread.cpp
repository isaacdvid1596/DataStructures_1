#include "Bread.h"



Bread::Bread()
{
	setWeight(0);
	this->next = NULL;
}

Bread::Bread(double w)
{
	setWeight(w);
	this->next = nullptr;
}


Bread::~Bread()
{

}

double Bread::getWeight()
{
	return this->weight;
}

void Bread::setWeight(double w)
{
	this->weight = w;
}
