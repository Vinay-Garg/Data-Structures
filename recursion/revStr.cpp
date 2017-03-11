#include <stdio.h>
#include <string.h>
void swap(char* a, char* b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void revStr(char* str, int n)
{
	if(n<2)
		return;

	swap(&str[0], &str[n-1]);
	revStr(str+1, n-2);
}

int main()
{
	char a[10] = "abcde\0";
	revStr(a, strlen(a));
	printf("%s\n", a);
}





