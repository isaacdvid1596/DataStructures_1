#pragma once
#include "Receipt.h"

class Hash
{

private:

	static const int tableSize = 4;

	Receipt *HashTable[tableSize];




public:
	Hash();
	~Hash();
	int hashFunction(int key);
	void addItem(int receiptNumber, string name, double amountDue);
	int numberOfIndexItems(int index);
	void printHashTable();
	void printBucketItems(int index);
	void removeItem(int receiptNumber);
};