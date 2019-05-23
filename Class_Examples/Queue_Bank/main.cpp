#include <iostream>
#include "Cashier.h"
#include "Customer.h"

using namespace std;

void Menu()
{
	char command = '\0';

	do {

		cout << "BANK MENU" << endl;
		cout << "A- A Priority Max" << endl;
		cout << "B- B Priority Worst" << endl;
		cout << "C- C Priority Medium Priority" << endl;
		cout << "D- D Inquiry [A.5 Second Priority]" << endl;
		cout << "E -Exit" << endl;
		cin >> command;

		switch (command)
		{
		case 'A':
			cout << "Priority Max" << endl;
			break;

		case 'B':
			cout << "Priority Worst" << endl;
			break;

		case 'C':
			cout << "Priority Medium Priority" << endl;
			break;

		case 'D':
			cout << "A.5 Second Priority" << endl;

		default:
			break;
		}
	} while (command != 'E');
}


int main()
{
	

}