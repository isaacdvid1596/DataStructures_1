#pragma once
#include <iostream>

using namespace std;

class Customer
{

private:
	char priorityTicket = '\0';

public:
	Customer();
	Customer(char);
	virtual ~Customer();
	Customer *next;
	void setpriorityTicket(char);
	char getpriorityTicket();
};

