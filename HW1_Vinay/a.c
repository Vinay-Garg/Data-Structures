#include<stdio.h>
int main()
{
	f1(5);
	char a[]={'E', 'D', 'C', 'B', 'A'};
	f2(a);
	f3(5);
	int b[]= {1,4,4,5,10,20,6,3,7,30};
	f4(b);
	f5(5);
}

/****************************************/
int f1(int n)
{int i,j;
	for(j=1; j<=n; j++)
		{
			for(i=1; i<=j; i++)
   			{printf("%d",i);}
			printf("\n");
		}
}

/****************************************/
int f2(char a[])
{int i,j;
	for(j=0; j<5; j++)
		{
			for(i=0; i<=j; i++)
   			{printf("%c",a[i]);}
			printf("\n");
		}
}

/****************************************/
int f3(int n)
{
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

/****************************************/
int f4(int a[])
{
	int i,max=0, max2=0, max3=0;
	for(i=0; i<10; i++)
			if(max<=a[i])
				max=a[i];
		
   			//printf("%d ",max);

	for(i=0; i<10; i++)
			if(max2<=a[i] && a[i]<max)
				max2=a[i];

				//printf("%d ",max2);

	for(i=0; i<10; i++)
			if(max3<=a[i] && a[i]<max2)
				max3=a[i];

				printf("third greatest number = %d \n",max3);
}

/****************************************/
int f5(int n)
{
	int i,j;
	for(j=1; j<=n; j++)
		{
			for(i=1; i<=n-j; i++)
			   printf(" ");

			for(i=1; i<=(j+1); i++)
			   printf("%d", i);
			

			printf("\n");
		}
}











