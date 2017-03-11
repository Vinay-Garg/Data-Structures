/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int FindMergeNode(Node *headA, Node *headB)
{
    Node *AP = headA;
    Node *BP = headB;
    
    while(AP != BP) 
    {
        AP = AP->next;
        BP = BP->next;
        if(AP==NULL) 
            AP = headB;
        
        if(BP==NULL) 
            BP = headA; 
    }
    return AP->data;
    // Complete this function
    // Do not write the main method. 
}
