/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
    if( (!head) || (!head->next) )
        return head;
    
    Node* rest = head->next;
    Node* newNode = Reverse(rest);
    
    // Node* iter = rest;
    // while(iter->next != NULL)
    //     iter = iter->next;
    
    rest->next = head;
    head->next = NULL;
    head = rest;
    
    return newNode;
  // Complete this method
}

