#include <iostream>
#include "cashReg.h"
#include "item.h"
using namespace std;

void itemDisplay();
void sellProduct(itemType &product, cashReg &pCounter);


int main()
{
	cashReg counter;
	itemType candy(100, 50);
	itemType chips(100, 65);
	itemType gum(75, 45);
	itemType cookies(100, 85);

	itemDisplay();
	int choice;
	cin >> choice;

	while(choice != 9)
	{
		switch(choice)
		{
			case 1: sellProduct(candy, counter);
				   break;
			case 2: sellProduct(chips, counter);
				   break;
			case 3: sellProduct(gum, counter);
				   break;
			case 4: sellProduct(cookies, counter);
				   break;
			default: cout << "Wrong selection" << endl;
		}

		itemDisplay();
		cin >> choice;
	}

	return 0;
}






void itemDisplay()
{
	cout << "** welcome to candy Machine **" << endl;
	cout << "1 - candy" << endl;
	cout << "2 - chips" << endl;
	cout << "3 - gum" << endl;
	cout << "4 - cookies" << endl;
	cout << "9 - to exit" << endl;
}

void sellProduct(itemType &product, cashReg &pCounter)
{
	int amt;
	int extraAmt;

	if(product.count() > 0)
	{
		cout << "please deposit " << product.productCost() 
										<< "cents" << endl;
		cin >> amt;

		if(amt < product.productCost() )
		{
			cout << "please deposit another " << product.productCost() - amt 
												<< " cents" << endl;
			cin >> extraAmt;
		}

		if(amt >= product.productCost() )
		{
			pCounter.acceptAmount(amt);
			product.makeSale();
			cout << "collect your item" << endl;
		}

		else
			cout << "Amount is not enough" 
						<< "Collect what you deposited" << endl;
	}

	else
		cout << "sorry, this item is sold out" << endl;
}