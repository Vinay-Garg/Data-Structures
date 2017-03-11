#include<stdio.h>
int main()
{
	int n=5;
	int i,j;
	for(j=1; j<=n; j++)
		{
			for(i=1; i<=n-j; i++)
			   printf(" ");

			for(i=j; i<=(2*j-1); i++)
			   printf("%d", i);

			for(i=2*j-2; i>j-1 ; i--)
			   printf("%d", i);

			printf("\n");
		}
}
