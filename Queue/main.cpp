#include <iostream>
#include "Queues.h"


using namespace std;

int main()
{

	Queues q;

	cout << "Enqueing" << endl;
	q.Enqueue(10);
	q.Enqueue(20);
	q.Enqueue(30);
	q.Enqueue(40);
	q.Enqueue(50);

	cout << "printing" << endl;
	q.Print();
	cout << "hello world" << endl;
	
	cout << "Dequeing" << endl;

	for (int i = 0; i < 5; i++)
	{
		q.Dequeue();
	}

	q.Print();
	
}