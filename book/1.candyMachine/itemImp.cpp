#include <iostream>
#include "item.h"
using namespace std;

int itemType:: count()
{
	return noOfItems;
}

int itemType:: productCost()
{
	return cost;
}

void itemType:: makeSale()
{
	noOfItems--;
}

itemType:: itemType(int setNoOfItems, int setCost)
{
	if(setNoOfItems >= 0)
		noOfItems = setNoOfItems;
	else
		noOfItems = 50;

	if(setCost >= 0)
		cost = setCost;
	else
		cost = 50;
}
