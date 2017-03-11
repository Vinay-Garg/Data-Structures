#include <iostream>
#include "cashReg.h"
using namespace std;

int cashReg:: currentBalance()
{
	return cashOnHand;
}

void cashReg:: acceptAmount(int amountIn)
{
	cashOnHand += amountIn;
}

cashReg:: cashReg(int cashIn)
{
	if(cashIn >= 0)
		cashOnHand = cashIn;
	else
		cashOnHand = 500;
}