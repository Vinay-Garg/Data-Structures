#include <stdio.h>
#include <string.h>

int elfish(char* str, int X)
{
	if(X == 7)
		return 1;

	if(str[0] == '\0')
		return 0;
	if (str[0] == 'e')
		X |= 1;
	else if (str[0] == 'l')
		X |= 2;
	else if (str[0] == 'f')
		X |= 4;
	
	return elfish(str+1, X);
}

int main()
{
	char set[10] = "eaafsl";
	printf("%d\n", elfish(set, 0) );
}






