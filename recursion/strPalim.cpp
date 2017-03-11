#include <stdio.h>
#include <string.h>

int isPalim(char* str, int n)
{
	if(n<2)
		return 1;
	return (str[0]==str[n-1] && isPalim(str+1, n-2));
}

int main()
{
	char a[10] = "abcba";
	printf("%d\n", isPalim(a, strlen(a)) );
}






