#pragma once
#include "Receipt.h"

class Hash
{
private:
	static const int tableSize = 10;

	Receipt *HashTable[tableSize];
	

public:
	Hash();
	~Hash();
	int HashFunction(int key);	
	void AddItem(Receipt *receipt);
	int NumberofItems(int index);
	void PrintHashTable();
	void PrintBucketItems(int index); 
	void RemoveItems(int receiptNumber);
};

