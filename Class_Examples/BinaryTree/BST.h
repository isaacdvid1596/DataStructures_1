#pragma once
#include <iostream>
#include "Node.h"

class BST
{
private:
	void addLeafPrivate(int key, Node *node);
	void PrintInOrderPrivate(Node *node);
	Node *ReturnNodePrivate(int key, Node* node);
public:
	Node *root;
	Node *CreateLeaf(int key);
	void addLeaf(int key);
	void PrintInOrder();
	Node *ReturnNode(int key);
	BST();
	~BST();
};

