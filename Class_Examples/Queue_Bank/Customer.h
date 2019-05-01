#pragma once
#include <iostream>

using namespace std;

class Customer
{

private:
	int ticketnumber;

public:
	Customer();
	Customer(int);
	virtual ~Customer();
	Customer *next;
	void setTicketNumber(int);
	int getTicketNumber();
};

