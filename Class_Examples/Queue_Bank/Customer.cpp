#include "Customer.h"



Customer::Customer()
{
	setTicketNumber(0);
	this->next = NULL;
}

Customer::Customer(int t)
{
	setTicketNumber(t);
	this->next = nullptr;
}

Customer::~Customer()
{
}

void Customer::setTicketNumber(int t)
{
	this->ticketnumber = t;
}

int Customer::getTicketNumber()
{
	return this->ticketnumber;
}
