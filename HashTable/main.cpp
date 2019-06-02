#include <iostream>
#include "Hash.h"
#include <string>

using namespace std;

int main()
{

	Hash h;
	string name;
	

	h.addItem("Isaac", "Green Tea");
	h.addItem("Leah", "Beer");
	h.addItem("Adler", "Black Tea");
	h.addItem("Odylia", "Jingsen Tea");
	h.addItem("Hilda", "Choco Milk");
	h.addItem("Abelard", "Coffee");
	h.addItem("Markus", "Iced Coffee");
	h.addItem("Augusta", "Caramel Milk");
	h.addItem("Oliver", "White Tea");
	h.addItem("Roselia", "Camomille Tea");
	h.addItem("Eriksen", "Orange Juice");
	h.addItem("Vlad", "Water");
	
	//h.printHashTable();

	h.PrintBucketItems(2);

	while (name != "exit")
	{
		cout << "Remove " << endl;
		cin >> name;
		if (name != "exit")
		{
			h.RemoveItem(name);
		}
	}


	h.PrintBucketItems(2);
	//h.FindDrink(name);

	//h.PrintBucketItems(6);


}