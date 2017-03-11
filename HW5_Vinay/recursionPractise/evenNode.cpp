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

/*************************/
void printEvenNodes(node* head)
{
	if(head == NULL || head-> next == NULL)	
		return;
	head = head->next;
	printf("%d ", head-> val);
	head = head->next;
	printEvenNodes(head);

}

/*************************/
int main()
{
	node* n = initializeRandomList(6);
	print(n);
	printf("\n");
	printEvenNodes(n);

	return 0;
}