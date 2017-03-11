#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char str1[10000], str2[10000];
    scanf("%s", str1);
    scanf("%s", str2);

    int a[26]={0};
    for (int i = 0; str1[i]!='\0'; i++)
    	a[str1[i] - 'a']++;

    for (int i = 0; str2[i]!='\0'; i++)
    	a[str2[i] - 'a']--;

    int s=0;
    for (int i = 0; i < 26; i++)
    	s += abs(a[i]);

    printf("%d\n", s);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
