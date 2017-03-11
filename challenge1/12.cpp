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
    for(int a0 = 0; a0 < n; a0++){
        char* s = (char *)malloc(10240 * sizeof(char));
        scanf("%s",s);
    

	    int a[1000] = {0};
	    for (int i = 0; s[i] != '\0'; i++)
	    	a[s[i] - 'a'] = 1;

	    int c=0;
	    for (int i = 0; i < 1000; i++)
	    {
	    	if(a[i])
	    		c++;
	    }

	    printf("%d\n", c);
	}
    return 0;
}
