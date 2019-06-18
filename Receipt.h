#pragma once
#include <iostream>
#include <string>

using namespace std;

class Receipt
{

private:
	int receiptNumber;
	string name;
	double amountDue;

public:
	Receipt *next;
	void setReceiptNumber(int receiptNumber);
	int getReceiptNumber();
	void setName(string name);
	string getName();
	void setAmountDue(double amountDue);
	double getAmountDue();
	Receipt();
	Receipt(int , double , string);
	~Receipt();
};

