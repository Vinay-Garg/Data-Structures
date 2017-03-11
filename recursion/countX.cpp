#include <stdio.h>
#include <string.h>

int countX(char* str, char X)
{
	if(str[0] == '\0')
		return 0;
	return ( (str[0]==X) + countX(str+1, X));
}

int main()
{
	char set[10] = "abcbaaa";
	char str = 'a';
	printf("%d\n", countX(set, str) );
}






