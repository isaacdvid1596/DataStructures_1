#include "Receipt.h"



Receipt::Receipt()
{
	setName("empty");
	setAmountDue(0.00);
	setReceiptNumber(0);
	this->next = NULL;
}

Receipt::Receipt(string name,double amountDue, int receiptNumber)
{

	setName(name);
	setAmountDue(amountDue);
	setReceiptNumber(receiptNumber);
	this->next = nullptr;
}

Receipt::~Receipt()
{

}

void Receipt::setName(string name)
{
	this->name = name;
}

void Receipt::setAmountDue(double amountDue)
{
	this->amountDue = amountDue;
}

void Receipt::setReceiptNumber(int receiptNumber)
{
	this->receiptNumber = receiptNumber;
}

string Receipt::getName()
{
	return this->name;
}

double Receipt::getAmountDue()
{
	return this->amountDue;
}

int Receipt::getReceiptNumber()
{
	return this->receiptNumber;
}
