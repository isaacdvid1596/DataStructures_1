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

int BST::ReturnRootKey()
{
	if (root != NULL)
	{
		return root->key;
	}
	else
	{
		return -1000;
	}
}

void BST::PrintChildren(int key)
{
	Node *temp = ReturnNode(key);

	if (temp != NULL)
	{
		cout << "Parent Node = " << temp->key << endl;
		
		if (temp->left == NULL)
		{
			cout << "Left child = NULL" << endl;
		}
		else
			cout << "Left child = " << temp->left->key << endl;

		if (temp->right == NULL)
		{
			cout << "Right child = NULL" << endl;
		}
		else
			cout << "Right child = " << temp->right->key << endl;
	}
	else
		cout << "Key " << key << "  doest not exist in the tree" << endl;

}

int BST::FindSmallest()
{
	return FindSmallestPrivate(root);
}


int BST::FindSmallestPrivate(Node *node)
{
	if (root == NULL)
	{
		cout << "tree is empty" << endl;
		return -1000;
	}
	else
	{
		if (node->left != NULL)
		{
			FindSmallestPrivate(node->left);
		}
		else
			return node->key;
	}
}

int BST::FindBiggest()
{
	return FindBiggestPrivate(root);
}

int BST::FindBiggestPrivate(Node *node)
{
	if (root == NULL)
	{
		cout << "tree is empty" << endl;
		return -1000;
	}
	else
	{
		if (node->right != NULL)
		{
			FindBiggestPrivate(node->right);
		}
		else
			return node->key;
	}
}