#pragma once
#include <iostream>

using namespace std;

class Bread
{

private:
	double weight;

public:
	Bread *next;
	Bread();
	Bread(double w);
	~Bread();
	double getWeight();
	void setWeight(double w);
};

