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
		hash = (hash)+(int)key[i] * 17;
	//	cout << "hash = " << hash << endl;
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
			temp = temp->next; //temp points to last element of that list
		}

		temp->next = newItem; //the last item of the list now points to the newItem

	}

}

int Hash::numberOfIndexItems(int index)
{
	int counter = 0;

	if (HashTable[index]->name == "empty")
	{
		return counter;
	}
	else
	{
		counter++;
		item *temp = HashTable[index];
		while (temp->next != NULL)
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
		number = numberOfIndexItems(i);
		cout << "-------------------" << endl;
		cout << "index = " << i << endl;
		cout<< "name = " <<HashTable[i]->name<<endl;
		cout<< "drink = " << HashTable[i]->drink<< endl;
		cout << "# of items = " <<number<<endl;
		cout << "-------------------" << endl;
	}

}


void Hash::PrintBucketItems(int index)
{
	item *temp = HashTable[index];

	if (temp->name == "empty")
	{
		cout << "Bucket = " <<index<<" is empty" << endl;
	}
	else
	{
		cout << "Bucket " << index <<" contains the following items"<<endl;

		while (temp!= NULL)
		{
			cout << "-------------------" << endl;
			cout << temp->name << endl;
			cout << temp->drink << endl;
			cout << "-------------------" << endl;

			temp = temp->next;
		}

	}

}


void Hash::FindDrink(string name)
{
	int index = hashFunction(name);

	bool nameFound = false;

	string drink;

	item *temp = HashTable[index];

	
	while (temp != NULL)
	{
		if (temp->name == name)
		{
			nameFound = true;
			drink = temp->drink;
		}

		temp = temp->next;
	}

	if (nameFound == true)
	{
		cout << "Favorite drink = " << drink << endl;
	}
	else
	{
		cout << name << "'s info cannot be found on the HashTable" << endl;
	}


}

void Hash::RemoveItem(string name)
{
	int index = hashFunction(name);

	item *deltemp;
	item *temp;
	item *temp1;


	//case 0 bucket empty

	if (HashTable[index]->name == "empty" && HashTable[index]->drink == "empty")
	{
		cout << "name " << name << " not found in The HashTable" << endl;
	}

	

	//case 1 only 1 item contained in bucket , the item has matching name

	else if (HashTable[index]->name == name && HashTable[index]->next == NULL)
	{
		HashTable[index]->name = "empty";
		HashTable[index]->drink = "empty";
		cout << name << " was removed from HashTable" << endl;
	}


	//case2 match in first item in bucket but there are more items in bucket
	else if (HashTable[index]->name == name && HashTable[index]->next != NULL)
	{
		deltemp = HashTable[index];
		HashTable[index] = HashTable[index]->next;
		delete deltemp;

		cout << name << " was removed from HashTable" << endl;
	}

	//case 3 bucket contains items but first item is not match
	else
	{
		temp = HashTable[index]->next;
		temp1 = HashTable[index];

		while (temp != NULL && temp1->name != name)
		{
			temp1 = temp;
			temp = temp->next;
		}
		//case 3.1 look through all items and there is no match

		if (temp == NULL)
		{
			cout << name << " cannot be found in the HashTable" << endl;
		}
		//case 3.2 look through all items and there is a match in remaining items
		else
		{
			deltemp = temp;
			temp = temp->next;
			temp1->next = temp;
			delete deltemp;
			cout << name << " was removed from the HashTable" << endl;
		}

	}
	
			

	


}

