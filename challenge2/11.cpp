#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
	int t, key, q[100000] ;
	int i=0, f=0, r=-1; 
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d", &key);

		if(key==1)
		{
			scanf("%d", &q[i]);
			i++;
			r++;
		}

		else if(key==2)
		{
			f++;
		}

		else if(key==3)
		{
			printf("%d\n", q[f]);
		}
	}

   /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
