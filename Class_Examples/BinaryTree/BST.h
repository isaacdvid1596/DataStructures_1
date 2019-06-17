#pragma once
#include <iostream>
#include "Node.h"

class BST
{
private:
	void addLeafPrivate(int key, Node *node);
	void PrintInOrderPrivate(Node *node);
	Node *ReturnNodePrivate(int key, Node* node);
	int FindSmallestPrivate(Node *node);
	int FindBiggestPrivate(Node *node);
	void RemoveNodePrivate(int key,Node *node);
	void PreOrderPrivate(Node *node);
	void PostOrderPrivate(Node *node);
	void InOrderPrivate(Node *node);
public:
	Node *root;
	Node *CreateLeaf(int key);
	void addLeaf(int key);
	void PrintInOrder();
	Node *ReturnNode(int key);
	int ReturnRootKey();
	void PrintChildren(int key);
	int FindSmallest();
	int FindBiggest();
	void RemoveNode(int key);
	void RemoveRootMatch();
	void RemoveMatch(Node *parent, Node* match, bool left);
	void PreOrder();
	void PostOrder();
	void InOrder();

	BST();
	~BST();
};

