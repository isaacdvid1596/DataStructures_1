#pragma once
#include "Element.h"


using namespace std;

class BinaryTree
{
public:
	Element *root;
	BinaryTree();
	~BinaryTree();
	Element *CreateLeaf(int key);
	void AddLeaf(int key);
	void AddLeafPrivate(int key , Element *n);
	void PrintOrder();
	void PrintOrderPrivate(Element *n);
};

