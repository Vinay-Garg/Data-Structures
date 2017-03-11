#include <stdio.h>
#include <string.h>

int Xish(char* set, char* str)
{
	if(set[0] == '\0')
		return 0;
	if(str[0] == '\0')
		return 1;

	int i = 0;
	while(set[i] != '\0')
	{
		if(set[i] == str[0])
			return Xish(set+1, str+1);
		i++;
		// return Xish(str+1, set);
	}
}


int main()
{
	char set[30] = "abcbaadvvinaysdsd";
	char str[10] = "vinay";
	char str2[10] = "zas";
	printf("%d\n", Xish(set, str));
	printf("%d\n", Xish(set, str2));
}






