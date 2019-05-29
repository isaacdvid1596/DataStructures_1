#include <iostream>
#include "Hash.h"
#include <string>

using namespace std;

int main()
{
	Hash h;

	int index;



	index = h.hashFunction("Isaac");

	cout << "index = " << index << endl;

}