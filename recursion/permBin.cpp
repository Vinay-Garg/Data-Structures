#include <stdio.h>
#include <string.h>

void permBin(int* a, int i, int n)
{
	if(i==n)
	{
		for (int j = 0; j < n; ++j)
			printf("%d", a[j]);
		printf("\n");
		return;
	}

	a[i] = 0;
	permBin(a, i+1, n);

	a[i] = 1;
	permBin(a, i+1, n);
}

void fun(int n)
{
	int a[20];
	permBin(a, 0, n);
}

int main()
{
	int a[10];
	fun(4);
}








