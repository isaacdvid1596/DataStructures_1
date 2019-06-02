#pragma once
#include <iostream>
#include <string>

using namespace std;

class Hash
{

private:
	static const int tableSize = 4 ;

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
	int numberOfIndexItems(int index);
	void printHashTable();
	void PrintBucketItems(int index);
	void FindDrink(string name);
	void RemoveItem(string name);


};

