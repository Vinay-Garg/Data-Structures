#include<stdio.h>
#include<stdlib.h>

struct stackNode
{
	int data;
	struct stackNode* next; 
	//int top;
} *top;
typedef struct stackNode stack;


/*******************/
stack* createNewNode(int val, stack* next)
{
	stack* newNode = (stack*)malloc(sizeof(stack));
	newNode->data = val;
	newNode->next = next;
	return newNode;
}



/*******************/
void push(int val)
{
	if(top == NULL)
		stack* newNode = createNewNode(val, NULL);
	
	stack* newNode = createNewNode(val, top);
	top = newNode;
}


/*******************/
void pop()
{
	if(top == NULL)
		printf("stack is empty\n");

	else
	{
		stack* temp = top;
		printf("\n%d", temp-> data);
		top = temp-> next;
		free(temp);
	}
}



/*******************/
void peep()
{
	if(top == NULL)
		printf("stack is empty\n");

	printf("%d\n", top-> data);
}


/*******************/
void fullPeep()
{
	if(top == NULL)
		printf("stack is empty\n");

	else
	{
		stack* temp = top;
		while(temp!= NULL)
		{
			printf("%d ", temp-> data);
			temp = temp-> next;
		}
	}
}

/*******************/
int main()
{
	push(5);
	push(4);
	//push(2);
	//peep();
	fullPeep();

	pop();
	pop();
	pop();
	fullPeep();

}






















