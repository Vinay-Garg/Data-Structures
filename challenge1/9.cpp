#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    scanf("%d",&n);
    char* s = (char *)malloc(10240 * sizeof(char));
    scanf("%s",s);
    int k; 
    scanf("%d",&k);
        
	for(int i=0; s[i] != '\0'; i++)
	{
	    if(s[i] >= 'a' && s[i] <= 'z')
	    {
	        s[i] -= 26 - k%26;
	        if(s[i] <	 'a') 
	        	s[i] += 26;
	    }

	    if(s[i] >= 'A' && s[i] <= 'Z')
	    {
	         s[i] += k%26;
	        if(s[i] > 'Z') 
	        	s[i] -= 26;
	    }
}
printf("%s", s);
return 0;
}
