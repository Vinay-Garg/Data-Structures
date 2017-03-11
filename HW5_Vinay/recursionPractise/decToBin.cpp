#include <stdio.h>

int decToBin(int n)
{
	if(n==0)
		return 0;

	return(decToBin(n/2)*10 + n%2);
}

int main()
{
	printf("%d\n", decToBin(12));
	printf("%d\n", decToBin(4));
	return 0;
}