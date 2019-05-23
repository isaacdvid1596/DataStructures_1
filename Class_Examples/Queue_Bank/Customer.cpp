#include "Customer.h"



Customer::Customer()
{
	setpriorityTicket('\0');
	this->next = NULL;
}

Customer::Customer(char c)
{
	setpriorityTicket(c);
	this->next = nullptr;
}

Customer::~Customer()
{

}

void Customer::setpriorityTicket(char c)
{
	this->priorityTicket = '\0';
}

char Customer::getpriorityTicket()
{
	return this->priorityTicket;
}
