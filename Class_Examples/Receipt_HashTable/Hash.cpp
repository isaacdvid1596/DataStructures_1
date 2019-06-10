#include "Hash.h"
#include <string>
#include <sstream>

Hash::Hash()
{
	for (int i = 0; i < tableSize; i++) //for cycle goes through the whole tablesize
	{
		HashTable[i] = new Receipt; //create receipt pointer pointing to first element on HT
		HashTable[i]->name = "empty";//set element on [i] to default empty value for name
		HashTable[i]->amountDue = 0.00; //set element on [i] to default value for amountDue
		HashTable[i]->receiptNumber = 0;//set element on [i] to default value for receiptNumber

	}
}


Hash::~Hash() //initializes Hash Table with default values
{
	
}

int Hash::hashFunction(int key)
{
	int hash = 0; //initialize hash int variable on 0
	int index; //create  index int variable

	std::string str = std::to_string(key); //convert int key to string

	for (int i = 0; i < str.length(); i++) //for cycle that goes through key from start to end
	{
		hash = (hash)+(int)str[i]; //hash in 0 adds itself + ASCII code of characters in key
		//cout << "hash" << hash << endl;
	}
	/*
	cout << "key [0]" << (int)str[0] << endl;
	cout << "key [1]" << (int)str[1] << endl;
	cout << "key [2]" << (int)str[2] << endl;
	cout << "key [3]" << (int)str[3] << endl;
	cout << "key [4]" << (int)str[4] << endl;
	*/

	index = hash % tableSize; //index  equals hash modulo of tablesize 
	return index; //return index
}

void Hash::addItem(int receiptNumber, string name, double amountDue)
{
	int index = hashFunction(receiptNumber); //create index int variable that receives index from HashFunction

	if (HashTable[index]->receiptNumber == 0) // if receiptNumber element in HT[i] == 0 
	{
		HashTable[index]->receiptNumber = receiptNumber; //assign values to each of the elements.
		HashTable[index]->name = name;
		HashTable[index]->amountDue = amountDue;
	}
	else
	{
		Receipt *temp = HashTable[index]; // create temporal pointer that points to first element on HT
		Receipt *newReceipt = new Receipt; //create  a new node and initialize it
		newReceipt->receiptNumber = receiptNumber; // assign all values to new Receipt element
		newReceipt->name = name;
		newReceipt->amountDue = amountDue;
		newReceipt->next = NULL; // make newReceipt next pointer , point to NULL;

		while (temp->next != NULL) //while temp points to anything but NULL
		{
			temp = temp->next; //temp points to next
		}

		temp->next = newReceipt; //when reaching the end , temp->next points to newReceipt

	}

}

int Hash::numberOfIndexItems(int index)
{
	int counter = 0; //create counter int in 0

	if (HashTable[index]->receiptNumber == 0) // if receiptnumber in HT start 0
	{
		return counter; //return 0
	}
	else
	{
		counter++; //increase counter
		Receipt *temp = HashTable[index]; //temp points to start of HT
		while (temp != NULL) //while temp is not NULL
		{
			counter++; //increase counter 
			temp = temp->next;//temp moves to temp->next position
		}

	}

	return counter; 



}

void Hash::printHashTable()
{
	int number;

	for (int i = 0; i < tableSize; i++)
	{
		number = numberOfIndexItems(i);
		cout << "---------------------" << endl;
		cout << "index = " << i << endl;
		cout << "Receipt = " << HashTable[i]->receiptNumber << endl;
		cout << "Name = " << HashTable[i]->name << endl;
		cout << "Amount Due = " << HashTable[i]->amountDue << endl;
		cout << "# of Items = " << number << endl;
		cout << "---------------------" << endl;
	}
}

void Hash::printBucketItems(int index)
{
	Receipt *temp = HashTable[index];

	if (temp->receiptNumber == 0)
	{
		cout << "Bucket = " << index << " is empty" << endl;
	}
	else
	{
		cout << " Bucket " << index << " contains the following items" << endl;
		while (temp != NULL)
		{
			cout << "-----------" << endl;
			cout << temp->receiptNumber << endl;
			cout << temp->name << endl;
			cout << temp->amountDue << endl;

			temp = temp->next;
		}
	}

}

void Hash::removeItem(int receiptNumber)
{
	int index = hashFunction(receiptNumber);

	Receipt *deltemp;
	Receipt *temp;
	Receipt *temp1;

	if ((HashTable[index]->receiptNumber == 0) && (HashTable[index]->name=="empty") && (HashTable[index]->amountDue=0.00))
	{
		cout << "receipt" << receiptNumber << "not found in the HashTable" << endl;
	}

	else if ((HashTable[index]->receiptNumber == receiptNumber) && (HashTable[index]->next = NULL))
	{
		HashTable[index]->receiptNumber = 0;
		HashTable[index]->name = "name";
		HashTable[index]->amountDue = 0.00;
		cout << receiptNumber << " removed from the HashTable" << endl;
	}

	else if (HashTable[index]->receiptNumber == receiptNumber && HashTable[index]->next != NULL)
	{
		deltemp = HashTable[index];
		HashTable[index]->receiptNumber = 0;
		HashTable[index]->name = "name";
		HashTable[index]->amountDue = 0.00;
		delete deltemp;
	}

	else
	{
		temp = HashTable[index]->next;
		temp1 = HashTable[index];

		while (temp != NULL && temp1->receiptNumber != receiptNumber)
		{
			temp1 = temp;
			temp = temp->next;
		}

		if (temp == NULL)
		{
			cout << receiptNumber << " cannot be found in HashTable" << endl;
		}
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