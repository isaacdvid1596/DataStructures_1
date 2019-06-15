#include <iostream>
#include "BinaryTree.h"
#include "Element.h"


using namespace std;

int main()
{


	int treekeys[16] = {50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80};

	BinaryTree t;

	cout << "printing tree in order before adding numbers" << endl;

	t.PrintOrder();


	for (int i = 0; i < 16; i++)
	{
		t.AddLeaf(treekeys[i]);
	}

	cout << "printing tree in order after adding numbers" << endl;

	t.PrintOrder();

}