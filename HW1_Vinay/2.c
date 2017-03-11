#include<stdio.h>
int main()
{
int i,j;
char a[]={'E', 'D', 'C', 'B', 'A'};

	for(j=0; j<5; j++)
		{
			for(i=0; i<=j; i++)
   			{printf("%c",a[i]);}
			printf("\n");
		}
}
