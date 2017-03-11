#include <iostream>
using namespace std;

#define MAX 4
struct queue
{
	int arr[MAX];
	int f;
	int r;
	int size;
};
typedef struct queue q;

int isFull(q* q1)
{
	return (q1->size==MAX);
}

int isEmpty(q* q1)
{
	return (q1->size==0);
}

int enqueue(q* q1, int data)
{
	if( !isFull(q1))
	{
		if( (q1->r) == MAX-1)
			q1->r = -1;

		q1->r++;
		q1->arr[q1->r] = data;
		q1->size++;
		return 1;
	}

	else
	{
		cout << "queue is FULL \n";
		return -1;
	}
}

int dequeue(q* q1)
{
	if( !isEmpty(q1))
	{
		int data = q1->arr[q1->f];
		q1->size--;
		q1->f++;

		if( (q1->f) == MAX)
			q1->f = 0;
		return data;
	}

	else
	{
		cout << "queue is Empty \n";
		return -1;
	}
}

int front(q* q1)
{
	return q1->arr[q1->f];
}


int rear(q* q1)
{
	return q1->arr[q1->r];
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