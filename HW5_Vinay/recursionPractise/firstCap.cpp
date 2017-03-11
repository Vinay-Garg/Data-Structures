#include <stdio.h>

char firstCap(char* str)
{
	if(str[0] == '\0')
		return 0;

	if( str[0]>='A' && str[0]<='Z' )
		return str[0];

	firstCap(str+1);
}

int main()
{
	char a[] = "adbCjijCdw";
	printf("%c\n", firstCap(a));

	char b[] = "sdAwdwd";
	printf("%c\n", firstCap(b));
	return 0;
}