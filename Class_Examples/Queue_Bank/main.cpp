#include <iostream>
#include "Cashier.h"
#include "Customer.h"

using namespace std;

void Menu()
{
	int option;
	do
	{
		cout << "---MENU---" << endl;
		cout << "1-Enqueue" << endl;
		cout << "2-Dequeue" << endl;
		cout << "3-Print" << endl;
		cout << "4-Exit" << endl;
		cin >> option;

		switch (option)
		{
		case 1:
			
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			cout << "Option not valid" << endl;
			break;
		}

	} while (option != 4);
}


int main()
{
	Cashier bank;
	Customer *customer;

	int ticket;
	for (int i = 0; i < 5; i++)
	{
		cout << "Add Customer to Queue" << endl;
		cout << "Enter ticket number" << endl;
		cin >> ticket;
		customer = new Customer(ticket);
		int test = bank.Enqueue(customer);

		if (test == 1)
		{
			cout << "Customer queued" << endl;
		}
	}
	
	bank.printQueue();


	for (int i = 0; i < 5; i++)
	{
		int test=bank.Dequeue(customer);
		if (test == 2)
		{
			cout << "Customer dequeued" << endl;
		}
	}

	
	//cout << "Number of customer today :" << endl;
	//bank.getCounter();


}