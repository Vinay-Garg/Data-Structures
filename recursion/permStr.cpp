#include <stdio.h>
#include <string.h>
void swap(char* ptr1, char* ptr2)
{
    char temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void permStr(char* str, int l)
{
	if(l<1)
		return;

	int i=0;
	int n=strlen(str);
	while(i != n-1)
	{
	printf("%s\n", str);
	swap(&(str[n-1]), &(str[n-2-i]));
	i++;
	}
	permStr(str, l-1);
	
}

int main()
{
	char a[10] = "abcd\0";
	int n=strlen(a);
	permStr(a, n);

	return 0;
}

