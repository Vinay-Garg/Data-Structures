#include <stdio.h>
#include <string.h>

/*******************/
void swapChar(char* a, char* b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

/*******************/
int isSpecial(char a)
{
	// if(a=='!'|| a=='@'|| a=='#'|| a=='$'|| a=='%'|| a=='^'|| a=='&'|| a=='*' || a==',')
	// 	return 1;

	// else
	// 	return 0;

	return !( (a>='A'&&a<='Z')||(a>='a'&&a<='z')||(a>='0'&a<='9') );
}

/*******************/
void rev(char* str, int len)
{
	if(len<2)
		return;

	if(isSpecial(str[0]))
	{
		rev(str+1, len-1);
		return; 
	}

	if(isSpecial(str[len-1]))
	{
		rev(str, len-1);
		return; 
	}
	
	swapChar(&str[0],&str[len-1]);
	rev(str+1,len-2);
}



/*******************/
int main()
{
  char str[]="#cd,$ghh^qw@#dw";
  rev(str, strlen(str));
  printf("%s\n", str);
 
  return 0;
}
















