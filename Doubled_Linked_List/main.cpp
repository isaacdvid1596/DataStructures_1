#include<iostream>

#include "DLList.h"

using namespace std;

int main()
{
	DLList DL;

	DL.createNode(10);
	DL.createNode(20);
	DL.createNode(30);
	DL.createNode(40);

	cout << "Display List" << endl;
	DL.displayList();

	cout << "Display Backwards" << endl;
	DL.displayListBackwards();
	
	cout << "Insert Element Start" << endl;
	DL.insertElementStart(1);
	DL.displayList();
	cout << "display backward" << endl;
	DL.displayListBackwards();
	
	cout << "Insert Element Position" << endl;
	DL.insertElementPosition(2, 70);
	DL.displayList();
	cout << "displaying backwards" << endl;
	DL.displayListBackwards();

	cout << "deleting starting element" << endl;
	DL.deleteElementStart();
	cout << "Display List" << endl;
	DL.displayList();
	cout << "displaying backwards" << endl;
	DL.displayListBackwards();

	cout << "deleting element at the end" << endl;
	DL.deleteElementEnd();
	cout << "Display List" << endl;
	DL.displayList();
	cout << "displaying backwards" << endl;
	DL.displayListBackwards();

	cout << "deleting element at position" << endl;
	DL.deleteElementPosition(2);
	cout << "Display List" << endl;
	DL.displayList();
	cout << "displaying backwards" << endl;
	DL.displayListBackwards();

	/*

	cout << "Insert Element End" << endl;
	DL.insertElementEnd(60);
	DL.displayList();
	DL.displayListBackwards();

	cout << "Insert Element Position" << endl;
	DL.insertElementPosition(2, 5);
	DL.displayList();
	*/
	
}