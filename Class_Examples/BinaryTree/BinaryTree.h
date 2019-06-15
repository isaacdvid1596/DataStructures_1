#pragma once
#include "Element.h"


using namespace std;

class BinaryTree
{

private:
	Element *root;
	Element *ReturnNodePrivate(int key, Element* n);
	void AddLeafPrivate(int key, Element *n);
	void PrintOrderPrivate(Element *n);
public:
	
	BinaryTree();
	~BinaryTree();
	Element *CreateLeaf(int key);
	void AddLeaf(int key);
	void PrintOrder();
	Element *ReturnNode(int key);
	int ReturnRootKey();
	void PrintChildren(int key);
};

