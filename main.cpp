#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List myList;

	myList.createNode(10);
	myList.createNode(20);
	myList.createNode(30);
	myList.createNode(40);
	
	cout << "Displaying List";

	cout << "\n--------------------------------------------------\n";

	myList.displayList();

	cout << "\n--------------------------------------------------\n";
	

	cout << "Inserting At End";

	cout << "\n--------------------------------------------------\n";

	myList.createNode(50);
	myList.displayList();

	cout << "Inserting at Start";

	cout << "\n--------------------------------------------------\n";

	myList.insertElementStart(1);
	myList.displayList();

	cout << "Inserting At Particular" << endl;

	cout << "\n--------------------------------------------------\n";

	myList.insertElementPosition(5, 60);
	myList.displayList();

	cout << "Deleting At Start";
	cout << "\n--------------------------------------------------\n";

	myList.deleteElementStart();
	myList.displayList();

	cout << "Deleting At End";

	cout << "\n--------------------------------------------------\n";

	myList.deleteElementEnd();
	myList.displayList();

	cout << "Deleting At Position";
	cout << "\n--------------------------------------------------\n";
	myList.deleteElementPosition(4);
	myList.displayList();

	system("pause");


}