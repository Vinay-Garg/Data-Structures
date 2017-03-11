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

int getLCM(int a, int b)
{
	return (a*b/ getGCD(a, b));
}

int main()
{
	printf("%d\n", getLCM(12, 18));
	printf("%d\n", getLCM(4, 3));
	return 0;
}