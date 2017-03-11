#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n1; 
    int n2; 
    int n3; 
    scanf("%d %d %d",&n1,&n2,&n3);

    int h1sum=0, h2sum=0, h3sum=0;

    int *h1 = malloc(sizeof(int) * n1);
    for(int h1_i = 0; h1_i < n1; h1_i++)
    {
       scanf("%d",&h1[h1_i]);
       h1sum += h1[h1_i];
    }
    int *h2 = malloc(sizeof(int) * n2);
    for(int h2_i = 0; h2_i < n2; h2_i++)
    {
       scanf("%d",&h2[h2_i]);
       h2sum += h2[h2_i];
    }
    int *h3 = malloc(sizeof(int) * n3);
    for(int h3_i = 0; h3_i < n3; h3_i++)
    {
       scanf("%d",&h3[h3_i]);
       h3sum += h3[h3_i];
    }
    
    int x=0, y=0, z=0;
    while((h1sum != h2sum) || (h2sum != h3sum) || (h1sum != h3sum))
    {
        if(h1sum>h2sum && h1sum>h3sum || h1sum==h2sum && h1sum>h3sum || h1sum>h2sum && h1sum==h3sum)
            h1sum -= h1[x++];

        if(h2sum>h3sum && h2sum>h1sum || h2sum==h3sum && h2sum>h1sum || h2sum==h1sum && h2sum>h3sum)
            h2sum -= h2[y++];

        if(h3sum>h2sum && h3sum>h1sum || h3sum==h2sum && h3sum>h1sum || h3sum==h1sum && h3sum>h2sum)
            h3sum -= h3[z++];
    }

    printf("%d\n", h1sum);

    return 0;
}
