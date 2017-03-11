#include <stdio.h>
#define max 4

typedef struct queues
{
	int f, r, size;
	int arr[max];
}queue;


/********************/
int isFull(queue* Q)
{	return (Q-> size == max); }


/********************/
int isEmpty(queue* Q)
{	return (Q-> size == 0); }


/********************/
int enqueue(queue* Q, int val)
{
	if( !isFull(Q))
	{
		if( (Q->r) == max-1)
			Q->r = -1;

		(Q->r)++;
		Q->arr[Q->r] = val;
		Q->size++;
		return 1;
	}

	else
		return -1;
}


/********************/
int dequeue(queue* Q)
{
	if( !isEmpty(Q))
	{
		int data = Q->arr[Q->f];
		Q->size--;
		(Q->f)++;

		if( (Q->f) == max)
			Q->f = 0;
		return data;
	}

	else
		return -1;
}



/********************/
int front(queue* Q)
{	return Q->arr[Q->f]; }


/********************/
int back(queue* Q)
{	return Q->arr[Q->r]; }




/********************/
int main()
{
	queue Q;
	(&Q)-> size=0;
	(&Q)-> f=0;
	(&Q)-> r=-1;

	printf("%d", enqueue(&Q, 1));	
	printf("%d", enqueue(&Q, 2));
	printf("%d", enqueue(&Q, 3));	
	printf("%d", enqueue(&Q, 4));
	printf("%d", enqueue(&Q, 5));	
	printf("%d\n", enqueue(&Q, 6));	
	printf("%d\n", front(&Q));
	printf("%d\n\n", back(&Q));

	//printf("%d\n", dequeue(&Q));	
	//printf("%d\n", dequeue(&Q));
	//printf("%d\n", dequeue(&Q));
	printf("%d\n", dequeue(&Q));	
	printf("%d\n\n", dequeue(&Q));

	printf("%d\n", front(&Q));
	printf("%d\n", back(&Q));

}




















