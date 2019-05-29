#include "Hash.h"



Hash::Hash()
{
	for (int i = 0; i < tableSize; i++)
	{
		HashTable[i]=new item;
		HashTable[i]->name = "empty";
		HashTable[i]->drink = "empty";
		HashTable[i]->next = NULL;
	}
}


Hash::~Hash()
{

}


int Hash::hashFunction(string key)
{

	int hash = 0;

	int index;

	//index = key.length();
	
	for (int i = 0; i < key.length(); i++)
	{
		hash = hash + (int)key[i];
		cout << "hash = " << hash << endl;
	}




	/*
	cout << "key [0]" << (int)key[0] << endl;
	cout << "key [1]" << (int)key[1] << endl;
	cout << "key [2]" << (int)key[2] << endl;
	cout << "key [3]" << (int)key[3] << endl;
	cout << "key [4]" << (int)key[4] << endl;
	*/


	index = hash % tableSize;

	return index;

}


void Hash::addItem(string name, string drink)
{
	int index = hashFunction(name);

	if (HashTable[index]->name == "empty") 
    //if element's name currently pointed at is empty then
	{
		HashTable[index]->name = name; 
		//access that elements name and drink replace it for the function's parameter
		HashTable[index]->drink = drink;
	}
	else //item already overwritten on that index
		//add another item to the end of the first or second or n item
	{
		item *temp = HashTable[index]; //temp points to first item on that index
		item *newItem = new item; //create new item;
		newItem->name = name; //give name to new item
		newItem->drink = drink; //give drink to new item
		newItem->next = NULL;//newItem->next points to null;

		while (temp->next != NULL) //traverse list till last item
		{
			temp = temp->next;
		}

		temp->next = newItem;

	}

}
