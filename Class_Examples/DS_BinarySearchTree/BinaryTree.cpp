#include "BinaryTree.h"



BinaryTree::BinaryTree()
{

}


BinaryTree::~BinaryTree()
{
	this->root = NULL;
}

Element *BinaryTree::CreateLeaf(int key)
{
	Element *newElement = new Element;
	newElement->key = key;
	newElement->left = NULL;
	newElement->right = NULL;

	return newElement;
}


void BinaryTree::AddLeaf(int key)
{
	AddLeafPrivate(key, root);
}

void BinaryTree::AddLeafPrivate(int key, Element *n)
{
	if (root == NULL)
	{
		root = CreateLeaf(key);
	}
	else
	{
		if (key < n->key)
		{
			if (n->left != NULL)
			{
				AddLeafPrivate(key, n->left);
			}
			else
				n->left = CreateLeaf(key);
		}
		else if (key > n->key)
		{
			if (n->right != NULL)
			{
				AddLeafPrivate(key, n->right);
			}
			else
				n->right = CreateLeaf(key);
		}

		else
			cout << "Key " << key << " already added to the tree" << endl;
	}
}

void BinaryTree::PrintOrder()
{
	PrintOrderPrivate(root);
}

void BinaryTree::PrintOrderPrivate(Element *n)
{
	if (root != NULL)
	{
		if (n->left != NULL)
		{
			PrintOrderPrivate(n->left);
		}
		cout << n->key << " ";
		if (n->right != NULL)
		{
			PrintOrderPrivate(n->right);
		}
	}
	else
		cout << "Tree is empty" << endl;
}