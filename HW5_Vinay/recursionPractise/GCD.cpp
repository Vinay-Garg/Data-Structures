#include <stdio.h>

int getGCD(int a, int b)
{
	while(a!=b)
	{
		if(a>b)
			return getGCD(a-b, b);

		else
			return getGCD(a, b-a);
	}
}

int main()
{
	printf("%d\n", getGCD(12, 18));
	printf("%d\n", getGCD(4, 3));
	return 0;
}