#include "Hash.h"
#include <string>
#include <sstream>

Hash::Hash()
{

}


Hash::~Hash()
{
	for (int i = 0; i < tableSize; i++)
	{
		HashTable[i] = new Receipt;
		HashTable[i]->name = "empty";
		HashTable[i]->amountDue = 0.00;
		HashTable[i]->receiptNumber = 0;

	}
}

int Hash::hashFunction(int key)
{
	int hash = 0;
	int index;

	std::string str = std::to_string(key);

	for (int i = 0; i < str.length(); i++)
	{
		hash = (hash)+(int)str[i];
	}

	index = hash % tableSize;
	return index;
}

void Hash::addItem(int receiptNumber, string name, double amountDue)
{
	int index = hashFunction(receiptNumber);

	if (HashTable[index]->receiptNumber == 0)
	{
		HashTable[index]->receiptNumber = receiptNumber;
		HashTable[index]->name = name;
		HashTable[index]->amountDue = amountDue;
	}
	else
	{
		Receipt *temp = HashTable[index];
		Receipt *newReceipt = new Receipt;
		newReceipt->receiptNumber = receiptNumber;
		newReceipt->name = name;
		newReceipt->amountDue = amountDue;
		newReceipt->next = NULL;

		while (temp != NULL)
		{
			temp = temp->next;
		}

		temp->next = newReceipt;

	}

}

int Hash::numberOfIndexItems(int index)
{
	int counter = 0;

	if (HashTable[index]->receiptNumber == 0)
	{
		return counter;
	}
	else
	{
		counter++;
		Receipt *temp = HashTable[index];
		while (temp != NULL)
		{
			counter++;
			temp = temp->next;
		}

	}

	return counter;


		
}

void Hash::printHashTable()
{
	int number;

	for (int i = 0; i < tableSize; i++)
	{
		number = numberOfIndexItems(i)
		
	}
}

void Hash::printBucketItems(int index)
{

}

void Hash::removeItem(int receiptNumber)
{

}
