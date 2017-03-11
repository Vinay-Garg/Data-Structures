#include <stdio.h>
#include <string.h>

void swap(char* a, char* b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

int isSpecial(char a)
{
	return (a=='!' || a=='@' || a=='#' || a=='%' || a=='&');
}

void revStrWOspecial(char* str, int n)
{
	if(n<2)
		return;

	if(isSpecial(str[0]))
		{
			revStrWOspecial(str+1, n-1);
			return;
		}

	if(isSpecial(str[n-1]))
		{
			revStrWOspecial(str, n-1);
			return;
		}

	swap(&str[0], &str[n-1]);
	revStrWOspecial(str+1, n-2);
}

int main()
{
	char a[10] = "a@#bcde&\0";
	revStrWOspecial(a, strlen(a));
	printf("%s\n", a);
}

