/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{

	if( (!headA) && (!headB) )
		return NULL;
	if(!headA)
		return headB;
	if(!headB)
		return headA;

	Node* newNode = (headA->data <= headB->data) ? headA : headB;
	newNode->data = (headA->data <= headB->data) ? headA->data : headB->data;
	newNode->next = (headA->data <= headB->data) ? MergeLists(headA->next, headB) : MergeLists(headA, headB->next);
	return newNode;
}
