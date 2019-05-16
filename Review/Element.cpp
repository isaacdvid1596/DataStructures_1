#include "Element.h"



Element::Element()
{
	setOperation(0);
	setTime(0);
	this->next = NULL;
}

Element::Element(int operation, int time)
{
	setOperation(operation);
	setTime(time);
	this->next = nullptr;
}


Element::~Element()
{

}

void Element::setOperation(int operation)
{
	this->optType = operation;
}

int Element::getOperation()
{
	return this->optType;
}

void Element::setTime(int time)
{
	this->aproxTime = time;
}

int Element::getTime()
{
	return this->aproxTime;
}