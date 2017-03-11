#include <stdio.h>

void printBinary(int n)
{
	if(n==0)
	{
		printf("\n");
		return;
	}

	printBinary(n/2);
	if(n&1)
		printf("1");
	else
		printf("0");
}

int main()
{
	printBinary(12);
	printBinary(64);
	return 0;
}