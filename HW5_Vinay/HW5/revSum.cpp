#include<stdio.h>
#include<math.h>
int sumDigits(int n)
{
	if(n==0)
		return 0;
	
	return (n%10 + sumDigits(n/10));
}

int reverseNumber(int n)
{
	if(n==0)
		return 0;
	
	static int r;	
	r = r*10 + n%10;
	reverseNumber(n/10);
	
	return r;	
}


int main()
{
	printf("%d\n", sumDigits(132));
	printf("%d\n", reverseNumber(132));
}
