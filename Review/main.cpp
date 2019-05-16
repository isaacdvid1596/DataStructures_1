#include <iostream>
#include "Queue.h"



using namespace std;


void QueueMenu()
{

	Queue q;

	int option = 0;

	do {

		cout << "Queue Menu" << endl;
		cout << "Select the operation type" << endl;
		cout << "0- Customer Service" << endl;
		cout << "1-Cashier" << endl;
		cout << "2-Other" << endl;
		cout << "3-Dequeue" << endl;
		cout << "4-Print Queue" << endl;
		cout << "5-Exit" << endl;
		cin >> option;

		switch (option)
		{
		case 0:
			{
			Element *element = new Element(option, 10);
			q.Enqueue(element);
			}
		break;

		case 1:
			{
			Element *element = new Element(option, 12);
			q.Enqueue(element);
			}
		break;

		case 2:
			{
			Element *element = new Element(option, 15);
			q.Enqueue(element);
			}
			break;

		case 3:
			{
			q.Dequeue();
			}
			break;

		default:
			break;

		}

	} while (option != 5);
}


int main()
{
	
	cout << "hello world" << endl;
	QueueMenu();
}
