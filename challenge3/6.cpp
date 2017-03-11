/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */


node * insert(node * root,int val)
{	
	if(!root)
	{
		root = (node*)malloc(sizeof(node));
		root->val = val;
		root->left = NULL;
		root->right = NULL;
		return;
	}   
 	
 	if(val < root->left->val)
 		insert(root->left, val);
 	else
 		insert(root->right, val);
}
