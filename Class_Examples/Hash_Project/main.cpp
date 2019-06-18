#include <iostream>
#include "Hash.h"
#include "Receipt.h"


using namespace std;

int main() {


	

	Receipt *r = new Receipt(252,5000.50,"Isaac");
	Receipt *r1 = new Receipt(1578, 11360.45, "David");
	Receipt *r2 = new Receipt(02314, 456.44, "Christopher");
	Receipt *r3 = new Receipt(4876666, 10.00, "Leah");
	Receipt *r4 = new Receipt(01114, 898.22, "Roberto");

	Hash h;

	//h.PrintHashTable();

	int receiptNum = 0;
	h.AddItem(r);
	h.AddItem(r1);
	h.AddItem(r2);
	h.AddItem(r3);
	h.AddItem(r4);

	h.PrintHashTable();
	h.PrintBucketItems(5);

	

	return 0;

}