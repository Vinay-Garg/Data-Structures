#include <stdio.h>
#include <stdlib.h>

struct listNode
{
	int data;
	struct listNode* next;
};
typedef struct listNode node;


node* createNewNode(int item)
{
	node* newNode = (node*) malloc(sizeof(node));
	newNode->data = item;
	newNode->next = NULL;
	return newNode;
}

node* randomList(int length)
{
	int random1 = rand()%100;
	node* newNode = createNewNode(random1);
	node* head = newNode;

	for(int i=0; i<length-1; i++)
	{
		int random = rand()%100;
		node* newNode1 = createNewNode(random);
		newNode->next = newNode1;
		newNode = newNode1;
	}
	return head;
}


void insertBegin(int item, node** headRef)
{
	node* newNode = createNewNode(item);
	newNode->next = *headRef;
	*headRef = newNode;
}

void insertEnd(int item, node* head)
{ 
	node* iter = head; 
	while(iter->next != NULL)
	{
		iter  = iter->next;
	}
	node* newNode = createNewNode(item);
	iter->next = newNode;
}

void insertMid(int item, int prevItem, node* head)
{
	node* iter = head;
	node* newNode = createNewNode(item);
	while(iter->next != NULL)
	{
		if(iter->data == prevItem)
		{
			newNode->next = iter->next;
			iter->next = newNode;
			iter = iter->next;
		}
		else
			iter = iter->next;
	}
}


void delBegin(node** headRef)
{
	node* temp = *headRef;
	*headRef = temp->next;
	free(temp);
}

void delEnd(node* head)
{
	node* iter = head;
	node* prev = head;
	while(iter->next != NULL)
	{
		prev = iter;
		iter = iter->next;
	}
	prev->next = NULL;
	free(iter);
}

void delMid(int item, node* head)
{
	node* iter = head;
	node* prev = head;
	while(iter->next != NULL)
	{
		if(iter->data == item)
		{
			prev->next = iter->next;
			prev = iter;
			iter = iter->next;
		}
		else
		{
			prev = iter;
			iter = iter->next;
		}
	}
	// free(iter);
}


void print(node* head)
{
	if(head == NULL)
		return;

	while(head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

int length(node* head)
{
	if(head == NULL)
		return 0;
	int l=0;
	while(head != NULL)
	{
		l++;
		head = head->next;
	}
	return l;
}


void update(int newItem, int prevItem, node* head)
{
	node* iter = head;
	while(iter->next != NULL)
	{
		if(iter->data == prevItem)
			iter->data = newItem;
		iter = iter->next;
	}
}


int Middle(node* head)
{
	if(head == NULL)
		return NULL;
	if(head->next == NULL)
		return head->data;

	int l = length(head);
	if(l&1)
		l = l/2+1;
	else
		l = l/2;

	node* iter = head;
	while(l != 1)
	{
		iter = iter->next;
		l--;
	}
	return iter->data;
}


// int MiddleFS(node* head)
// {
// 	if(head == NULL)
// 		return NULL;
// 	if(head->next == NULL)
// 		return head->data;

// 	node* f = head->next;
// 	node* s = head;
// 	while(f->next->next != NULL)
// 	{
// 		s = s->next;
// 		f = f->next->next;	
// 		if(f->next != NULL)
// 			return f->next->data;
		
// 			return s->data;
// 	}
// }


void reverse(node** headRef)
{
	if(*headRef == NULL || (*headRef)->next == NULL)
		return;

	node* rest = (*headRef)->next;
	
	reverse(&rest);
	node* iter = rest;
	while(iter->next != NULL)
		iter = iter->next;

	iter->next = *headRef;
	(*headRef)->next = NULL;
	*headRef = rest;	
}



int main()
{
	node* ll = randomList(5);
	print(ll);
	printf("length = %d \n\n", length(ll));

	insertBegin(199, &ll);
	print(ll);
	printf("length = %d \n\n", length(ll));

	insertMid(299, 199, ll);
	print(ll);
	printf("length = %d \n\n", length(ll));

	insertEnd(399, ll);
	print(ll);
	printf("length = %d \n\n", length(ll));

	delBegin( &ll);
	print(ll);
	printf("length = %d \n\n", length(ll));

	delMid(15, ll);
	print(ll);
	printf("length = %d \n\n", length(ll));

	delEnd(ll);
	print(ll);
	printf("length = %d \n\n", length(ll));

	update(599, 77, ll);
	print(ll);
	printf("length = %d \n\n", length(ll));

	printf("Middle = %d \n\n", Middle(ll));

	reverse(&ll);
	print(ll);
	printf("length = %d \n\n", length(ll));

	return 0;
}






















