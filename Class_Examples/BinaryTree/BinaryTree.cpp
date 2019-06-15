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


Element *BinaryTree::ReturnNode(int key)
{
	 return ReturnNodePrivate(key, root);
}

Element *BinaryTree::ReturnNodePrivate(int key, Element* node)
{
	if (node != NULL)
	{
		if (node->key == key)
		{
			return node;
		}
		else
		{
			if (key < node->key)
			{
				return ReturnNodePrivate(key, node->left);
			}
			else
			{
				return ReturnNodePrivate(key, node->right);
			}
		}
	}
	else
		return NULL;
}


int BinaryTree::ReturnRootKey()
{
	if (root != NULL)
	{
		return root->key;
	}
	else
		return -1000;
}

void BinaryTree::PrintChildren(int key)
{
	Element *node = ReturnNode(key);

	if (node != NULL)
	{
		cout << "Parent Node = " << node->key << endl;

		if (node->left == NULL)
		{
			cout << "left child = null" << endl;
		}
		else
		{
			cout << "left child = " << node->left->key << endl;
		}


		if (node->right == NULL)
		{
			cout << "right child = null" << endl;
		}
		else
		{
			cout << "right child = " << node->right->key << endl;
		}


	}
	else
		cout << "key " << key << " not in the tree" << endl;
}