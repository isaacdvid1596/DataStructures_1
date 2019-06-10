#include  <iostream>
#include "Hash.h"

using namespace std;

int main()
{


	Hash h;

	//h.printHashTable();

	
	h.addItem(12578, "Isaac", 3800.95);
	h.addItem(8597, "Peterson", 857.88);
	h.addItem(12772, "Leah", 5400.72);
	h.addItem(784122, "Addler", 7415.22);
	h.addItem(681544, "Abelard", 32.45);
	

	h.printHashTable();


}