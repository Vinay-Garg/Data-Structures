#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		char str[10000];
		scanf("%s", str);
		int l = strlen(str);

		int a[26]={0}, b[26]={0}, c=0;

		if(l & 1)
			c = -1;
		
		else
		{
			for (int i = 0; i < l/2; i++)
			{
				a[str[i] - 'a']++;
				b[str[l-1-i] - 'a']++;
			}


			for (int i = 0; i < 26; i++)
			{
				if(a[i] > b[i] && a[i]!=0) 
					c += abs(a[i] - b[i]);
			}
		}
		printf("%d\n", c);
	}

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
