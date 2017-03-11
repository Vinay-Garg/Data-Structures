#include<stdio.h>
int main()
{
int i;
int a[]= {1,4,4,5,10,20,6,3,7,30};
printf("array = ");
for(i=0; i<10; i++)
	printf("%d ",a[i]);

int max=0, max2=0, max3=0;
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

				printf("\nthird greatest number = %d \n",max3);
}
