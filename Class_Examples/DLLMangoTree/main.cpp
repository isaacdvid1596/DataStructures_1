#include <iostream>
#include "mangoFruit.h"
#include "mangoTree.h"

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

void MenuMangoTree()
{
	int option = 0;
	int pos = 0;
	int test = 0;
	double weight;

	mangoTree t;


	do
	{
		cout << "---MENU---" << endl;
		cout << "Select option" << endl;
		cout << "1-Add Fruit" << endl;
		cout << "2-Insert Fruit" << endl;
		cout << "3-Delete Fruit" << endl;
		cout << "4-Print Fruit Weight" << endl;
		cout << "5-Exit Program" << endl;

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

			if (test == 5)
				{
				cout << "Mango Added" << endl;
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

		default:
			cout << "Unknown command please enter a valid option" << endl;
			break;
			}
		} while (option != 5);
	} 



int main()
{
	MenuMangoTree();
}