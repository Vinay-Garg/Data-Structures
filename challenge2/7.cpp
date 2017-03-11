Node* createNewNode(int item)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = item;
    newNode->next = NULL;
    newNode->prev = NULL;
	return newNode;
}

Node* SortedInsert(Node *head, int item)
{
    Node* iter = head;
	Node* newNode = createNewNode(item);

	if(!head)
		return newNode;

    if(item < head->data)
    {
        newNode->next = head;
        head = newNode;
    }

	else
	{	
		while((iter->next) && item > iter->next->data )
			iter = iter->next;
    
		newNode->prev = iter;
	    newNode->next = iter->next;
	    iter->next = newNode;
    }
	    return head;
}



Node* SortedInsert(Node* head, int item)
{
    Node* iter = head;
    Node* new_node = createNewNode(item);

    /* Special case for the head end */
    if (head == NULL || item <= (head)->data)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        while (iter->next!=NULL && item > iter->next->data)
        {
            iter = iter->next;
        }
        new_node->next = iter->next;
        iter->next = new_node;
    }
    return head;
}