/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
	if( (!head) || (!head->next) )
		return head;

	Node* iter = NULL;
	Node* del = NULL;
	Node* comp = head;
	while( (comp != NULL) && (comp->next != NULL) )
	{
        iter = comp;
		while( (iter->next != NULL) )
		{
			if(iter->next->data == comp->data)
			{
			del = iter->next;
			iter->next = iter->next->next;
            free(del);
			}
			else
				iter = iter->next;
		}
		comp = comp->next;
	}
	return head;
}
