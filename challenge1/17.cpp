#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int t;
	scanf("%d" , &t);
	while(t--)
	{
	    int m,n,j;scanf("%d %d" , &m, &n);
	    int a[n];
        for(int i=0;i<n;i++)
	       scanf("%d", &a[i]);
            
	    for(int i=0;i<n;i++)
	    {
	    	for (int j = 0; j < n; j++)
	    	{
	    		if(i != j)
	    		{
	    			if(a[i] + a[j] == m && i>j)
                    {
                        printf("%d %d\n", j+1, i+1);
	    			    break;
                    }
	    		}
	    	}
         }
	}
	return 0;
}