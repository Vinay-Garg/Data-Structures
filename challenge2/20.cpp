#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int maxR(int a[],int x,int i,int n)
{
	while(i<=n)
	{
	    if(x >= a[i])
	        i++;
	    else
	        return i;  
	}
	return 0;
}

int maxL(int a[],int x,int i)
{
	while(i>0)
	{
	    if(x >= a[i])
	        i--;
	    else
	        return i;
	}
	return 0;
}

int main() 
{
	int n, l, r, temp_p, p=0, i, i, x;
	scanf("%d", &n);
	int a[n];

	for(int i=1; i<=n; i++)
	    scanf("%d", &a[i]);
	
	for(int i=1;i<=n;i++)
	{
	    if(i==1 || i==n)
	        temp_p=0;

	    else 
	    {
	        l=maxL(a,a[i],i-1);
	        r=maxR(a,a[i],i+1,n);
	        prod=l*r;
        }  	

	    if(temp_p > p)
	    	p = temp_p;
	}
	printf("%d",p);
	return 0;
}
