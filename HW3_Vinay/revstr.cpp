#include<stdio.h>
#include<string.h>
void reverseString(char* str, int len)
{
  if(len<2)
    return;
    
  reverseString(str,len-1);
  char temp;
  
  
  for(int i=(len-1) ;i>0; i--)
  {
  	temp=str[0];
    str[0]=str[len-1];
	str[len-1]=temp;
  }
}



int main()
{
  char str[]="abcdef";
  int len, i;
  len=strlen(str);
  reverseString(str,len);
  for(i=0; i<len; i++)
  	printf("%c", str[i]);

	return 0;
}

