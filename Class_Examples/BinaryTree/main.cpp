#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
	int treeKeys[16] = {50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80};

	BST t;

	

	cout << "printing the tree in order before adding numbers" << endl;
	t.PrintInOrder();

	for (int i = 0; i < 16; i++)
	{
		t.addLeaf(treeKeys[i]);
	}

	cout << "printing the tree in order after adding numbers" << endl;


	t.PrintInOrder();


	t.PreOrder();

	t.PostOrder();

	//t.PrintInOrder();

	cout << endl;

	t.RemoveNode(50);

	cout << endl;

	t.PrintInOrder();

	/*
	for (int i = 0; i < 16; i++)
	{
		t.PrintChildren(treeKeys[i]);
		cout << endl;
	}
	*/

	//cout << "smallest value = " << t.FindSmallest() << endl;
	//cout << "biggest value =" << t.FindBiggest() << endl;
	

}