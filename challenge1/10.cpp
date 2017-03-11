#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    char c;
int a[26]={0}, i;

while(scanf("%c",&c)==1)
{
    if(c>='a'&&c<='z')
        a[c-'a'] = 1;
    else if(c>='A'&&c<='Z')
        a[c-'A'] = 1;
}

for(i=0;i<26;i++)
    {
    if(a[i]==0)
        break;
    }
if(i==26)
    printf("pangram");
else
    printf("not pangram");
return 0;
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
