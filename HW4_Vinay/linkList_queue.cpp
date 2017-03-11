#include<stdio.h>
#include<stdlib.h>

struct queueNode
{
	int data;
	struct queueNode* next; 
} *f, *r;
typedef struct queueNode queue;


/*******************/
queue* createNewNode(int val, queue* next)
{
	queue* newNode = (queue*)malloc(sizeof(queue));
	newNode->data = val;
	newNode->next = next;
	return newNode;
}

/*******************/
void enqueue(int val)
{
	queue* newNode = createNewNode(val, NULL);

	if(f == NULL)	
		f = r = newNode;
	
	r->next = newNode;
	r = newNode;
}

/*******************/
void dequeue()
{
	if(f == NULL)
		printf("queue is empty\n");

	else
	{
		queue* temp = f;
		printf("\n%d", temp-> data);
		f = f-> next;
		free(temp);
	}
}
/*******************/
void front()
{
	if(f == NULL)
		printf("queue is empty\n");

	printf("%d\n", f-> data);
}

/*******************/
void rear()
{
	if(r == NULL)
		printf("queue is empty\n");

	printf("%d\n", r-> data);
}


/*******************/
void fullPeep()
{
	if(f == NULL)
		printf("queue is empty\n");

	else
	{
		queue* temp = f;
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
	enqueue(5);
	enqueue(4);
	enqueue(3);
    front();
    rear();
	fullPeep();

	dequeue();
	dequeue();
	dequeue();
	fullPeep();

}






















