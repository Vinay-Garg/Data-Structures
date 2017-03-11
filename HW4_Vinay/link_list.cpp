#include <stdio.h>
#include <stdlib.h>	

struct listNode
{
	int val;
	struct listNode* next; 
};
typedef struct listNode node;


/*************************/
node* createNewNode(int data, node* next)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->val = data;
	newNode->next = next;
	return newNode;
}


/*************************/
node* initializeRandomList(int length)
{
	int random = rand()%100;
	node* head = NULL;
	node* newNode = createNewNode(random, NULL);
	head = newNode;

	for(int i=1; i<length; i++)
	{
		int random = rand()%100;
		node* newNode1 = createNewNode(random, NULL);
		newNode->next = newNode1;
		newNode = newNode-> next;
	}
	return head;
}


/*************************/
void print(node* p)
{
	if(p==NULL)
		printf("list is empty\n");
	while(p!= NULL)
	{
		printf("%d ", p-> val);
		p = p-> next;
	}
}


/***********************/
int length(node* head)
{
	if(head == NULL)
		return 0;

	int count = 0;
	while(head!= NULL)
	{
		count++;
		head = head-> next;
	}
	return count;
}


/*********************/
void addFront(node** headRef, int data)
{
	node* newNode = createNewNode(data, *headRef);
	*headRef = newNode;
}


/********************/
void addEnd(node** headRef, int data)
{
	node* newNode = createNewNode(data, NULL);
	if(*headRef == NULL)
	{
		*headRef = newNode;
		return;
	}

	node* iter = *headRef;
	while(iter-> next != NULL)
		iter = iter-> next;
	iter-> next = newNode;
}


/*********************/
void removeFront(node** headRef)
{
	if(*headRef == NULL)	//empty list
		return;

	if((*headRef)-> next == NULL)	//only head
	{
		*headRef = NULL;
		return;
	}

	node* temp = *headRef;
	*headRef = temp-> next;
	free(temp);
}


/********************/
void removeEnd(node** headRef)
{
	if(*headRef == NULL)	//empty list
		return;

	if((*headRef)-> next == NULL)	//only head
	{
		*headRef = NULL;
		return;
	}


	node* iter = *headRef;
	node* prev = *headRef;
	while(iter-> next != NULL)
	{
		prev = iter;
		iter = iter-> next;
	}	

	prev->next = NULL;
	free(iter);
}



/*******************/
void reverseList(node** headRef)
{
	if( (*headRef == NULL) || ((*headRef)-> next == NULL) )
		return;

	node* rest = (*headRef)-> next;
	reverseList(&rest);
	
	node* iter = rest;
	while(iter->next != NULL)
		iter = iter-> next;

	iter-> next = *headRef;
	(*headRef)->next = NULL;
	*headRef = rest;
}


/******************/
void deleteByValue(node* head, int data)
{
	node* prev = NULL;
	node* iter = head;

	while(iter-> next != NULL)
	{
		if(iter->val == data)
		{
			prev-> next = iter->next;
			prev = iter;
			iter = iter-> next;
		}

		else
		{
			prev = iter;
			iter = iter-> next;
		}
	}						
}


/******************/
void replaceValue(node* head, int data, int newData)
{
	node* iter = head;
	while(iter->next != NULL)
	{
		if(iter->val == data)
			iter->val = newData;
		iter = iter-> next;
	}
}


int main()
{
	srand(time(NULL));
	//node* head = NULL;
	node *head = initializeRandomList(5);
	print(head);
	printf("\n%d \n\n", length(head));

	addFront(&head, 50);
	print(head);
	printf("\n%d \n\n", length(head));

	addEnd(&head, 50);
	print(head);
	printf("\n%d \n\n", length(head));

	removeEnd(&head);
	print(head);
	printf("\n%d \n\n", length(head));

	removeFront(&head);
	print(head);
	printf("\n%d \n\n", length(head));

	deleteByValue(head, 77);
	print(head);
	printf("\n%d \n\n", length(head));

	replaceValue(head, 86, 100);
	print(head);
	printf("\n%d \n\n", length(head));

	reverseList(&head);
	print(head);
	printf("\n%d \n\n", length(head));

	

	return 0;
}




























