#include <iostream>
#include "Bread.h"
#include "StackBread.h"

using namespace std;

int main()
{
	
	StackBread stack;
	Bread b;
	Bread *bread;

	double weight;

	for (int i = 0; i < 5; i++)
	{
		cout << "Add Bread to Stack" << endl;
		cout << "Add Weight" << endl;
		cin >> weight;
		bread = new Bread(weight);
		int test = stack.Push(bread);

		if (test == 1)
		{
			cout << "Bread pushed" << endl;
		}
	}

	stack.Print();
	cout << endl;


	for (int i = 0; i < 5; i++)
	{
		cout << "Removing Bread" << endl;
		int test = stack.Pop();
		if (test == 2)
		{
			cout << "Bread popped" << endl;
		}
	}

	


	//cout << "Number of slices" << endl;
	

}