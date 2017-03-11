#include<stdio.h>
#include<stdlib.h>
int main()
{
//allocation
	//z=2;y=3;x=4   -->  p[2][3][4]
	int i,j,k;
	int ***p;
	p = (int***) malloc(sizeof(int**) * 2);
	
	for(i=0; i<4; i++)
	{
		p[i] = (int**) malloc(sizeof(int*) * 3);
		
		for(j=0; j<3; j++)
			p[i][j] = (int*) malloc(sizeof(int) * 4);
	}

//int p[2][3][3];	int i,j,k;
//printing		
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 3; j++)
		{
        	for(k = 0; k < 4; k++)
       	   {
            p[i][j][k] = k;
            printf("%d ", p[i][j][k]);
       	   }
        printf("\n");
    	}
    printf("\n");
	}
	
	return 0;	
}
	
