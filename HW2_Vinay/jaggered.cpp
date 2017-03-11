#include<stdio.h>
#include<stdlib.h>
int main()
{	
//allocation
int i,j,k;
	int **p;
	p = (int**) malloc(sizeof(int*) * 5);
	
	for(i=0; i<5; i++)
		p[i] = (int*) malloc(sizeof(int) * (i+1));
		
//printing		
	
	for(i = 0; i < 5; i++)
	{
        for(j = 0; j < i+1; j++)
        {
            p[i][j] = j;
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    
	return 0;
}
