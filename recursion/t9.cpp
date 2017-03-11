#include <stdio.h>

char table[10][5] = {"","", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};


void perm(int *numArr, int i, char* output, int n)
{
	if(i==n)
	{
		printf("%s\n", output);
		return;
	}

	int number = numArr[i];
	char* str = table[number];

	for (int j = 0; str[j] != '\0'; ++j)
	{
		output[i] = str[j];
		perm(numArr, i+1, output, n);
	}
}

void t9(int *numbers)
{
	int length = sizeof(numbers)/sizeof(numbers[0]);
	char output[length+1] = "\0";
	perm(numbers, 0, output, length);
}

int main()
{
	int arr[10] = {9,4};
	t9(arr);
	return 0;
}




