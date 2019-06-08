#pragma once
#include <iostream>

using namespace std;

class Receipt
{

private:
	

public:
	string name;
	double amountDue;
	int receiptNumber;
	Receipt *next;
	Receipt();
	Receipt(string,double,int);
	~Receipt();
	void setName(string name);
	void setAmountDue(double amountDue);
	void setReceiptNumber(int receiptNumber);
	string getName();
	double getAmountDue();
	int getReceiptNumber();


};

