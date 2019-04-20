#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	Stack s;
	
	cout << "---Pushing---" << endl;
	s.Push("Isaac", 69);
	s.Push("Julio", 59);
	s.Push("David", 49);
	s.Push("Ramos", 39);

	s.Print();
	
	for (int i = 0; i < 5; i++)
	{
		cout << "---Popping---" << endl;
		s.Pop();
	}

	cout << "Pushing new stack" << endl;
	s.Push("Isaac", 79);
	s.Push("Julio", 89);
	s.Push("David", 99);
	s.Push("Ramos", 109);
	s.Print();

}