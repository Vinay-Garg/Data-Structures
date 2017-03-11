/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    
    for(int i=0; i<101; i++)
        {
            if(!head)
                return false;
            else
                head=head->next;
        }
    
    return true;
    // Complete this function
    // Do not write the main method
}
