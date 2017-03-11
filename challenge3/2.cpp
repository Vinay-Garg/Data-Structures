//LCA

/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/

node* lca(node *root, int  v1, int v2)
{
	if(!root)
		return NULL;

	if(root->data==v1 || root->data==v2)
		return root;

	node* l = lca(root->left, v1, v2);
	node* r = lca(root->right, v1, v2);

	if(l && r)
		return root;

	if(!l && !r)
		return NULL;

	return l!=NULL ? l: r;
}
