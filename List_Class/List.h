#pragma once
#include <iostream>

using namespace std;

struct node
{
	int data;
	node *next;
};


class List
{

	
private:
	node *head;
	node *tail;
	

public:
	List();
	virtual ~List();
	void createNode(int value);
	void displayList();
	void insertElementStart(int value);
	void insertElementEnd(int value);
	void insertElementPosition(int pos,int value);
	void deleteElementEnd();
	void deleteElementStart();
	void deleteElementPosition(int pos);


};

