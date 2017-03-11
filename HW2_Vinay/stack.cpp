#include<stdio.h>
#include<stdlib.h>
#define MAX 3

typedef struct stack
{
	int arr[MAX];
	int top;
}stack;

int isEmpty(struct stack *s1)
{	return (s1->top == 0); }

int isFull(struct stack *s1)
{	return (s1->top == MAX); }


int push(struct stack *s1, int val)
{
	if( isFull(s1) ) 
	{
		printf("Stack is full\n");	
		return 0;
	}
		(s1->top)++;
		s1->arr[s1->top] = val;
		
		return 1;
}


int pop(struct stack *s1)
{
	if( isEmpty(s1) )
	{
		printf("Stack is empty\n");	
		return 0;
	}
		(s1->top)--;
		return 1;
}

int peep(struct stack *s1)
{
	if( isEmpty(s1) )
	{
		printf("Stack is empty\n");	
		return 0;
	}
		return s1->arr[s1->top];
}


int main()
{	
	stack *my = (stack*) malloc(sizeof(stack));
	my->top =0;
	push(my, 1);
	printf("%d\n", peep(my));
	push(my, 2);	
	push(my, 3);	
	push(my, 4);
	printf("%d\n", peep(my));
	pop(my);
	printf("%d\n", peep(my));

	return 0;
}
