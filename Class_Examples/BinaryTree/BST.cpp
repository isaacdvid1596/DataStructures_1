#include "BST.h"



BST::BST()
{
	this->root = NULL;
}


BST::~BST()
{

}

Node *BST::CreateLeaf(int key)
{
	Node *newNode = new Node;
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

void BST::addLeaf(int key)
{
	addLeafPrivate(key, root);
}

void BST::addLeafPrivate(int key,Node *node)
{
	if (root == NULL)
	{
		root = CreateLeaf(key);
	}
	else
	{
		if (key < node->key)
		{
			if (node->left != NULL)
			{
				addLeafPrivate(key, node->left);
			}
			else
				node->left = CreateLeaf(key);
		}
		else if (key > node->key)
		{
			if (node->right != NULL)
			{
				addLeafPrivate(key, node->right);
			}
			else
				node->right = CreateLeaf(key);
		}
		else
			cout << "key " << key << " already added to the tree" << endl;
	}
}


void BST::PrintInOrder()
{
	PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(Node *node)
{
	if (root != NULL)
	{
		if (node->left != NULL)
		{
			PrintInOrderPrivate(node->left);
		}
		cout << node->key << " ";
		if (node->right != NULL)
		{
			PrintInOrderPrivate(node->right);
		}
	}
	else
		cout << "Tree is empty" << endl;
}

Node *BST::ReturnNode(int key)
{
	return ReturnNodePrivate(key, root);
}

Node *BST::ReturnNodePrivate(int key, Node* node)
{

}