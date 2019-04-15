#pragma once
#include <iostream>

using namespace std;

struct node {

	int data;
	node *next;
	node *back;

};



class DLList
{

private:
	node *head;
	node *tail;

public:
	DLList();
	virtual ~DLList();
	void createNode(int value);
	void displayList();
	void displayListBackwards();
	void insertElementStart(int value);
	void insertElementEnd(int value);
	void insertElementPosition(int pos, int value);
	void deleteElementEnd();
	void deleteElementStart();
	void deleteElementPosition(int pos);

};

