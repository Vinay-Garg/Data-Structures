#include <stdio.h>
#include <stdlib.h>

#define MAX 3
struct stackNode
{
	int data;
	int top;
	struct stackNode* next;
};
typedef struct stackNode node;


node* createNewNode(int item)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = item;
	newNode->next = NULL;
	newNode->top = 0;
	return newNode;
}

void print(node* head)
{
	if(head == NULL)
		return;

	node* iter = head;
	while(iter != NULL)
	{
		printf("%d ", iter->data);
		iter = iter->next;
	}
	printf("\n");
}


int isFull(node* s)
{
	return (s->top == MAX-1);
}

int isEmpty(node* s)
{
	return (s->top == -1);
}


void push(int item, node* *headRef)
{
	node* newNode = createNewNode(item);
	if(*headRef == NULL)
	{
		*headRef = newNode;
		return;
	}

	node* iter = *headRef;
	if(isFull(iter))
	{
		printf("FULL\n");
		return;
	}
	while(iter->next != NULL)
		iter = iter->next;
	
	iter->next = newNode;
	++(*headRef)->top;
}


void pop(node* head)
{
	if(head == NULL || isEmpty(head))
	{
		printf("pop EMPTY\n");
		return;
	}

	node* iter = head;
	node* prev = head;
	while(iter->next != NULL)
	{
		prev = iter;
		iter = iter->next;
	}
	prev->next = NULL;
	free(iter);
	head->top--;

}


void peep(node* head)
{
	if(head == NULL || isEmpty(head))
	{
		printf("peep EMPTY\n");
		return;
	}
	node* iter = head;
	while(iter->next != NULL)
		iter = iter->next;
	printf("%d\n", iter->data);
}


int main()
{
	node* ll = NULL;
	peep(ll);

	push(6, &ll);
	// printf("top %d\n", ll->top);
	peep(ll);

	push(7, &ll);
	peep(ll);

	push(8, &ll);
	peep(ll);

	push(9, &ll);
	peep(ll);

	pop(ll);
	peep(ll);

	pop(ll);
	peep(ll);

	pop(ll);
	peep(ll);


	return 0;
}









