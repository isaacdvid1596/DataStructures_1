#pragma once
#include <iostream>
#include <string>

using namespace std;

class Hash
{

private:
	static const int tableSize = 10 ;

	struct item
	{
		string name;
		string drink;
		item *next;
	};

	item *HashTable[tableSize]; 

	 
	//core of hash , array with tablesize amount of buckets, 
	//each of the buckets contain a pointer that points to next item




public:
	Hash();
	~Hash();
	int hashFunction(string key);
	void addItem(string name, string drink);


};

