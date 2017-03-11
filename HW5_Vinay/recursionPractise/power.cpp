#include <stdio.h>

int power(int x, int n)
{
	if(n==0)
		return 1;

	int c = power(x, n/2);
	if(n&1)
		return c*c*x;
	else
		return c*c;
}

int main()
{
	printf("%d\n", power(12, 0));
	printf("%d\n", power(4, 3));
	return 0;
}