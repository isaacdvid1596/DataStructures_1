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

void  BST::RemoveNode(int key)
{
	RemoveNodePrivate(key,root);
}

void  BST::RemoveNodePrivate(int key , Node *node)
{
	if (root != NULL)
	{
		if (root->key == key)
		{
			RemoveRootMatch();
		}
		else
		{
			if (key < node->key && node->left!=NULL)
			{
				if (node->left->key == key)
				{
					RemoveMatch(node, node->left,true);
				}
				else
				{
					RemoveNodePrivate(key, node->left);
				}
			}
			else if (key > node->key && node->right != NULL)
			{
				if (node->right->key == key)
				{
					RemoveMatch(node, node->right, false);
				}
				else
				{
					RemoveNodePrivate(key, node->right);
				}
			}
			else
			{
				cout << "key = " << key << " was not found" << endl;
			}
		}
	}
	else
		cout << "Tree is empty" << endl;
}

void  BST::RemoveRootMatch()
{
	if (root != NULL)
	{
		Node *deltemp;
		deltemp = root;
		int rootKey = root->key;
		int SmallestInRightSubtree;

		//case 0, no children

		if (root->left == NULL && root->right == NULL)
		{
			root = NULL;
			delete deltemp;
		}

		//case 1 , root no one child

		else if (root->left == NULL && root->right != NULL)
		{
			root = root->right;
			deltemp->right = NULL;
			delete deltemp;
			cout << "root " << rootKey << " was deleted ,  new root is " << root->key << endl;
		}

		else if (root->left != NULL && root->right == NULL)
		{
			root = root->left;
			deltemp->left = NULL;
			delete deltemp;
			cout << "root " << rootKey << " was deleted ,  new root is " << root->key << endl;
		}

		//case 2 root has 2 children

		else
		{
			SmallestInRightSubtree = FindSmallestPrivate(root->right);
			RemoveNodePrivate(SmallestInRightSubtree, root);
			root->key = SmallestInRightSubtree;
			cout << "root key " << rootKey << " was overwritten with " << root->key << endl;
		}



	}
	else
		cout << " Cannot remove root , Tree is empty" << endl;
}

void  BST::RemoveMatch(Node *parent, Node* match, bool left)
{
	if (root != NULL)
	{
		Node *deltemp;
		int matchKey = match->key;
		int smallestinright;

		//case 0 , no children

		if (match->left == NULL && match->right == NULL)
		{
			deltemp = match;
			
			if (left == true)
			{
				parent->left = NULL;
			}
			else
			{
				parent->right = NULL;
			}

			delete deltemp; 

		}

	}
	else
		cout << "cannot remove match , tree is empty" << endl;
}

void BST::PreOrder()
{
	PreOrderPrivate(root);

}

void BST::PostOrder()
{
	PostOrderPrivate(root);
}

void BST::InOrder()
{
	InOrderPrivate(root);
}

void BST::PreOrderPrivate(Node *node)
{
	if (root != NULL)
	{
		cout << node->key << endl;

		if (node->left != NULL)
		{
			PreOrderPrivate(node->left);
		}

		if (node->right != NULL)
		{
			PreOrderPrivate(node->right);
		}
	}
	else
	{
		cout << "tree is empty" << endl;
	}
}

void BST::PostOrderPrivate(Node *node)
{
	if (root != NULL)
	{
		if (node->left != NULL)
		{
			PostOrderPrivate(node->left);
		}

		if (node->right != NULL)
		{
			PostOrderPrivate(node->right);
		}

		cout << node->key << endl;
	}
	else
	{
		cout << "tree is empty" << endl;
	}
}

void BST::InOrderPrivate(Node *node)
{

}