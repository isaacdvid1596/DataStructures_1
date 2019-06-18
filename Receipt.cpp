#include "Receipt.h"



Receipt::Receipt()
{
	setReceiptNumber(0);
	setName("empty");
	setAmountDue(0.00);
	this->next = NULL;
}

Receipt::Receipt(int receiptNumber, double amountDue, string name)
{
	setReceiptNumber(receiptNumber);
	setName(name);
	setAmountDue(amountDue);
	this->next = nullptr;
}


Receipt::~Receipt()
{

}

void Receipt::setReceiptNumber(int receiptNumber)
{
	this->receiptNumber = receiptNumber;
}

int Receipt::getReceiptNumber()
{
	return this->receiptNumber;
}

void Receipt::setName(string name)
{
	this->name = name;
}

string Receipt::getName()
{
	return this->name;
}

void Receipt::setAmountDue(double amountDue)
{
	this->amountDue = amountDue;
}

double Receipt::getAmountDue()
{
	return this->amountDue;
}
