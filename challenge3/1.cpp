/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/
void printLeft(node* root)
{
	if(!root)
		return;

	printLeft(root->left);
	printf("%d ", root->data);
}

void printRight(node* root)
{
	if(!root)
		return;

	printf("%d ", root->data);
	printRight(root->right);
}

void top_view(node * root)
{
	if(!root)
		return;

	printLeft(root->left);
	printf("%d ", root->data);
  	printRight(root->right);
}











/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/
/*
void top_view(node * root)
{
	if(root->left != NULL)
	{
		root->left->right = NULL;
		top_view(root->left);
	} 

	printf("%d ", root->data);

	else if(root->right != NULL)
	{
		root->right->left = NULL;
		top_view(root->right);
	} 	

}
