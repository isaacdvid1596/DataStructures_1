#include <iostream>
#include <list>
#include <conio.h>
#include "mangoFruit.h"
#include "mangoTree.h"

void MenuSecondMangoTree();
void MenuMangoTree();
//mangoTree mergeTrees(mangoTree list1, mangoTree list2);

using namespace std;

/*
void addMango()
{
	double weight;
	cout << "Enter mango weight" << endl;
	cin >> weight;
	mangoFruit *mango = new mangoFruit(weight);

}
*/

void mergeTrees(mangoTree *list1 , mangoTree *list2)
{
	list1->tail->next = list2->head;
	list2->head->prev = list1->tail;
}

mangoTree t;
mangoTree t2;
mangoTree t3;





void MenuMangoTree()
{
	int option = 0;
	int option2tree = 0;
	int pos = 0;
	int test = 0;
	int mangoTreeCounter = 0;
	double weight;




	do
	{
		cout << "---MENU---" << endl;
		cout << "Select option" << endl;
		cout << "1-Add Fruit" << endl;
		cout << "2-Insert Fruit" << endl;
		cout << "3-Delete Fruit" << endl;
		cout << "4-Print Fruit Weight" << endl;
		cout << "6-Get Tree Weight" << endl;
		cout << "7-Get Tree Fruits" << endl;
		cout << "8-Create Second Tree" << endl;
		cout << "9-Print Both Mango Trees" << endl;
		cout << "10-Merge" << endl;
		cout << "11-Print Merged Tree" << endl;
		cout << "12- Exit Program" << endl;

		cin >> option;

		switch (option)
		{
		case 1:
		{
			cout << "Adding Fruit to the Tree..." << endl;
			cout << "Enter mango weight" << endl;
			cin >> weight;
			mangoFruit *mango = new mangoFruit(weight);
			test = t.addMango(mango);

			mangoTreeCounter++;

			if (t.fruitMaxCapacityExceeded() == true)
			{
				cout << "Max Fruit Capacity Reached" << endl;
				break;
			}
			else
			{

				if (t.treeMaxWeightExceeded() == true)
				{
					cout << "Tree Max Weight Reached" << endl;
					break;
				}

				else
				{
					if (test == 5)
						cout << "Mango Added Succesfully" << endl;
				}

			}




		}

		break;
		case 2:
		{
			cout << "Inserting Fruit to the Tree..." << endl;
			cout << "Enter mango weight" << endl;
			cin >> weight;
			cout << "Enter desired position" << endl;
			cin >> pos;
			mangoFruit *mango = new mangoFruit(weight);
			test = t.insertMango(mango, pos);

			switch (test)
			{
			case(-1):
				cout << "Position does not exist on tree" << endl;
				break;
			case(-2):
				cout << "The position is negative , cannot be added" << endl;
				break;
			case(-3):
				cout << "Mango could not be added" << endl;
				break;
			case 0:
				cout << "Mango added to the tree" << endl;
				break;
			case 1:
				cout << "Mango inserted succesfully" << endl;
				break;

			default:
				cout << "Position or weight invalid" << endl;
				break;
			}
		}



		break;
		case 3:
		{
			cout << "Deleting Fruit to the Tree..." << endl;

			cout << "Enter position you want to delete" << endl;
			cin >> pos;
			test = t.deleteMango(pos);
			if (test == 0)
			{
				cout << "Mango successfully deleted" << endl;
			}
		}

		break;
		case 4:
			cout << "Printing Fruit Weight..." << endl;
			t.printMangoTree();
			cout << "Mango Tree Printed succesfully" << endl;
			break;
		case 5:
			cout << "Exiting program..." << endl;
			break;

		case 6:
			cout << "Getting Tree Weight" << endl;
			t.getTotalWeight();
			break;

		case 7:
			cout << "Getting Tree Number of Fruits" << endl;
			t.getFruitQuantity();
			break;

		case 8:
			cout << "Create Second Tree" << endl;
			MenuSecondMangoTree();
			break;

		case 9:
			cout << "Printing Both Mango Trees" << endl;
			t.printMangoTree();
			t2.printMangoTree();
			break;

		case 10:
		{
			cout << "Printing Merge Lists" << endl;
			t3.mergeTrees(t, t2);
		}
			break;

		case 11:

			break;

		default:
			cout << "Unknown command please enter a valid option" << endl;
			break;
		}
	} while (option != 11);
}



void MenuSecondMangoTree()
{
	int option = 0;
	int pos = 0;
	int test = 0;
	int mangoTreeCounter = 0;
	double weight;

	//mangoTree t2;


	do
	{
		cout << "---MENU---" << endl;
		cout << "Select option" << endl;
		cout << "1-Add Fruit" << endl;
		cout << "2-Insert Fruit" << endl;
		cout << "3-Delete Fruit" << endl;
		cout << "4-Print Fruit Weight" << endl;
		cout << "6-Get Tree Weight" << endl;
		cout << "7-Get Tree Fruits" << endl;
		//cout << "8-Create Second Tree" << endl;
		cout << "8-Exit Program" << endl;

		cin >> option;

		switch (option)
		{
		case 1:
		{
			cout << "Adding Fruit to the Tree..." << endl;
			cout << "Enter mango weight" << endl;
			cin >> weight;
			mangoFruit *mango = new mangoFruit(weight);
			test = t2.addMango(mango);

			mangoTreeCounter++;

			if (t2.fruitMaxCapacityExceeded() == true)
			{
				cout << "Max Fruit Capacity Reached" << endl;
				break;
			}
			else
			{

				if (t2.treeMaxWeightExceeded() == true)
				{
					cout << "Tree Max Weight Reached" << endl;
					break;
				}

				else
				{
					if (test == 5)
						cout << "Mango Added Succesfully" << endl;
				}

			}




		}

		break;
		case 2:
		{
			cout << "Inserting Fruit to the Tree..." << endl;
			cout << "Enter mango weight" << endl;
			cin >> weight;
			cout << "Enter desired position" << endl;
			cin >> pos;
			mangoFruit *mango = new mangoFruit(weight);
			test = t2.insertMango(mango, pos);

			switch (test)
			{
			case(-1):
				cout << "Position does not exist on tree" << endl;
				break;
			case(-2):
				cout << "The position is negative , cannot be added" << endl;
				break;
			case(-3):
				cout << "Mango could not be added" << endl;
				break;
			case 0:
				cout << "Mango added to the tree" << endl;
				break;
			case 1:
				cout << "Mango inserted succesfully" << endl;
				break;

			default:
				cout << "Position or weight invalid" << endl;
				break;
			}
		}



		break;
		case 3:
		{
			cout << "Deleting Fruit to the Tree..." << endl;

			cout << "Enter position you want to delete" << endl;
			cin >> pos;
			test = t2.deleteMango(pos);
			if (test == 0)
			{
				cout << "Mango successfully deleted" << endl;
			}
		}

		break;
		case 4:
			cout << "Printing Fruit Weight..." << endl;
			t2.printMangoTree();
			cout << "Mango Tree Printed succesfully" << endl;
			break;
		case 5:
			cout << "Exiting program..." << endl;
			break;

		case 6:
			cout << "Getting Tree Weight" << endl;
			t2.getTotalWeight();
			break;

		case 7:
			cout << "Getting Tree Number of Fruits" << endl;
			t2.getFruitQuantity();
			break;



		default:
			cout << "Unknown command please enter a valid option" << endl;
			break;
		}
	} while (option != 8);
}




int main()
{
	MenuMangoTree();
}