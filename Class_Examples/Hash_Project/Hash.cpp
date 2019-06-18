#include "Hash.h"
#include <sstream>

Hash::Hash()
{
	for (int i = 0; i < tableSize; i++)
	{
		HashTable[i] = new Receipt();
	}
}


Hash::~Hash()
{
	Receipt *temp;

	for (int i = 0; i < tableSize; i++)
	{
		while (HashTable[i] != NULL)
		{
			temp = HashTable[i];
			HashTable[i] = HashTable[i]->next;
			delete temp;
		}
	}

}

int Hash::HashFunction(int key)
{
	int hash = 0;
	int index;

	std::string str = std::to_string(key);


	for (int i = 0; i < str.length(); i++)
	{
		hash = hash + (int)str[i];
	}

	index = hash % tableSize;

	return index;

}

void Hash::AddItem(Receipt *receipt)
{
	int index = HashFunction(receipt->getReceiptNumber());

	//case n->receiptnumber==0

	if (HashTable[index]->getReceiptNumber() == 0)
	{
		HashTable[index] = receipt;
	}
	
	else
	{
		Receipt *temp = HashTable[index];

		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = receipt;

	}

}

int Hash::NumberofItems(int index)
{
	int counter = 0; //create counter int in 0

	if (HashTable[index]->getReceiptNumber()==0) // if receiptnumber in HT start 0
	{
		return counter; //return 0
	}
	else
	{
	
		Receipt *temp = HashTable[index]; //temp points to start of HT
		while (temp != NULL) //while temp is not NULL
		{
			counter++; //increase counter 
			temp = temp->next;//temp moves to temp->next position
		}

	}

	return counter;



}

void Hash::PrintHashTable()
{
	int number;

	for (int i = 0; i < tableSize; i++)
	{
		number = NumberofItems(i);
		cout << "---------------------" << endl;
		cout << "index = " << i << endl;
		cout << "Receipt = " << HashTable[i]->getReceiptNumber() << endl;
		cout << "Name = " << HashTable[i]->getName() << endl;
		cout << "Amount Due = " << HashTable[i]->getAmountDue() << endl;
		cout << "# of Items = " << number << endl;
		cout << "---------------------" << endl;

	}

}

void Hash::PrintBucketItems(int index)
{
	Receipt  *temp = HashTable[index];

	if (temp->getReceiptNumber() == 0)
	{
		cout << "Bucket " << index << " is empty" << endl;
	}
	else
	{
		cout << "Bucket " << index << " contains the following items" << endl;
		while (temp != NULL)
		{
			cout << "-------------" << endl;
			cout << temp->getName() << endl;
			cout << temp->getAmountDue() << endl;
			cout << temp->getReceiptNumber() << endl;
			cout << "-------------" << endl;

			temp = temp->next;
		}
	}
}

void Hash::RemoveItems(int receiptNumber)
{
	int index = HashFunction(receiptNumber);

	Receipt *deltemp;
	Receipt *temp;
	Receipt *temp1;

	//case 0 bucket is empty

	if (HashTable[index]->getReceiptNumber() == 0)
	{
		cout << "ReceiptNumber" << receiptNumber << " not found" << endl;
	}

	// case 1 only 1 item match
	else if (HashTable[index]->getReceiptNumber() == receiptNumber && HashTable[index]->next == NULL)
	{
		HashTable[index] = new Receipt();
		cout << receiptNumber << " was removed from HashTable" << endl;
	}

	//case 2 first item is match but there are more items
	else if (HashTable[index]->getReceiptNumber() == receiptNumber && HashTable[index]->next != NULL)
	{
		deltemp = HashTable[index];

		HashTable[index] = HashTable[index]->next;

		delete deltemp;

		cout << receiptNumber << endl;
	}

	else
	{
		//case 3 bucket contains items but first  items is not match

		temp = HashTable[index]->next;
		temp1 = HashTable[index];

		while (temp != NULL && temp->getReceiptNumber!=receiptNumber)
		{
			temp1 = temp;
			temp = temp->next; // IT REACHES NULL
		}
		//case 3.1 look through all items but no match
		if (temp == NULL)
		{
			cout << receiptNumber << " cannot be found in the Hashtable" << endl;
		}
		//case 3.2 look through all items and there is a match
		else
		{
			deltemp = temp;
			temp = temp->next;
			temp1->next = temp;
			delete deltemp;
			cout << receiptNumber << " was removed from HashTable" << endl;
		}
			
	}
	


}
