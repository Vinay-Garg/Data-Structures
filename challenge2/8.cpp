/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* Reverse(Node* head)
{
    if( (!head) || (!head->next))
        return head;
      
    Node* iter = head;
    Node* newHead;
    while(iter)
    {
        newHead = iter;
        iter = iter->next;
        newHead->next = newHead->prev;
        newHead->prev = iter; 
    }
    return newHead;
    // Complete this function
    // Do not write the main method. 
}
