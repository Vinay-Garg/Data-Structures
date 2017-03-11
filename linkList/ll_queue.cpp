#include <stdio.h>
#include <stdlib.h>

#define MAX 4
struct queueNode
{
	int data;
	struct queueNode* next; 
	int f,r,size;
};
typedef struct queueNode node;

node* createNewNode(int item)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = item;
	newNode->next = NULL;
	return newNode;
}

void enqueue(int item, node* *headRef)
{
	if(!isFull(*headRef))
	{
		if((*headRef)->r == MAX-1)
			(*headRef)->r = -1;

		(*headRef)->r++;
		(*headRef)->data = item;
		(*headRef)->size++;
		return ;
	}

	else
	{
		cout << "queue is FULL \n";
		return ;
	}
}


void dequeue(node* *headRef)
{
	if(!isEmpty(*headRef))
	{
		if((*headRef)->f == MAX)
			(*headRef)->f = 0;

		(*headRef)->f++;
		(*headRef)->size++;
		return ;
	}

	else
	{
		cout << "queue is Empty \n";
		return ;
	}
}



void front(node* head)
{
	if(head == NULL || isEmpty(head))
	{
		printf("front EMPTY\n");
		return;
	}
	node* iter = head;
	while(iter->next != NULL)
		iter = iter->next;
	printf("%d\n", iter->data);
}


int rear(node* node1)
{
	return node1->arr[node1->r];
}


int main()
{
	queue Q;
	(&Q)-> size=0;
	(&Q)-> f=0;
	(&Q)-> r=-1;

	cout << enqueue(&Q, 1) << endl;	
	cout << enqueue(&Q, 2) << endl;
	cout << enqueue(&Q, 3) << endl;	
	cout << enqueue(&Q, 4) << endl;
	cout << enqueue(&Q, 5) << endl;	
	cout << enqueue(&Q, 6) << endl;	
	cout << front(&Q) << endl;
	cout << rear(&Q) << endl;

	cout << dequeue(&Q) << endl;	
	cout << dequeue(&Q) << endl;

	cout << front(&Q) << endl;
	cout << rear(&Q) << endl;

}




