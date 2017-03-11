#include <stdio.h>
#include <stdlib.h>

struct treeNode
{
	int data;
	struct treeNode* left;
	struct treeNode* right;
	struct treeNode* parent;
};
typedef struct treeNode node;

node* createNewNode(int item, treeNode* left, treeNode* right, treeNode* parent)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = item;
	newNode->left = left;
	newNode->right = right;
	newNode->parent = parent;
	return newNode;
}

void printInOrder(node* root)
{
	if(root == NULL)
		return;
	printInOrder(root->left);
	printf("%d ", root->data);
	printInOrder(root->right);
}

void insertBST(node* *rootRef, int item, treeNode* parent = NULL)
{
	if((*rootRef) == NULL)
	{
		*rootRef = createNewNode(item, NULL, NULL, NULL);
		return;
	}

	if(item  < (*rootRef)->data)
		insertBST(&(*rootRef)->left, item, (*rootRef));
	else
		insertBST(&(*rootRef)->right, item, (*rootRef));
}

node* getSuccessor(node* root)
{
	if(root->right == NULL)
		return NULL;

	node* s = root->right;
	while(s->left != NULL)
		s = s->left;
	return s;
}

void deleteBST(node* *rootRef, int item)
{
	if((*rootRef)->data == item)
	{
		if((*rootRef)->left == NULL)
		{
			node* del = (*rootRef);
			(*rootRef) = (*rootRef)->right;
			free(del);
		}
		else if((*rootRef)->right == NULL)
		{
			node* del = (*rootRef);
			(*rootRef) = (*rootRef)->left;
			free(del);
		}
		else
		{
			node* s = getSuccessor((*rootRef));
			(*rootRef)->data = s->data;
			deleteBST(&s, item);
		}
	}
	else if( item < (*rootRef)->data)
		deleteBST(&(*rootRef)->left, item);
	else if( item > (*rootRef)->data)
		deleteBST(&(*rootRef)->right, item);
}

int height(node* root)
{
	if(!root)
		return 0;
	int lh = height(root->left);
	int rh = height(root->right);

	return ( 1 + ((lh>rh)? lh: rh) );
}


int isBalanced(node* root)
{
	if(!root)
		return 1;

	int lh = height(root->left);
	int rh = height(root->right);

	return (abs(lh-rh)<2 && isBalanced(root->left) && isBalanced(root->right));
}


int getMax(node* root)
{
	if(!root)
		return -999999;

	int maxL = root->data;
	maxL = (getMax(root->left) > maxL)? getMax(root->left): maxL;

	int maxR = root->data;
	maxR = (getMax(root->right) > maxR)? getMax(root->right): maxR;
	
	return ( ((maxL>maxR)? maxL: maxR) );
}

int getMin(node* root)
{
	if(!root)
		return 999999;

	int minL = root->data;
	minL = (getMin(root->left) < minL)? getMin(root->left): minL;

	int minR = root->data;
	minR = (getMin(root->right) < minR)? getMin(root->right): minR;
	
	return ( ((minL<minR)? minL: minR) );
}

node* balancedTreeFromArray(int arr[], int start, int end)
{
	if(start > end)
		return NULL;
	int mid = (start+end)/2;
	node* newNode = createNewNode(arr[mid], 
						balancedTreeFromArray(arr, start, mid-1), 
						balancedTreeFromArray(arr, mid+1, end),
						newNode);	
	return newNode;
}


#include <iostream>
using namespace std;
int path[100];
void rootToLeafPath(node* root, int n=0)
{
	if(!root)
		return;

	if( (!root->left) && (!root->right))
	{
		for (int i = 0; i < n; ++i)
			cout << path[i] << "->";
		printf("%d ", root->data);
		return;
	}
	path[n] = root->data;
	rootToLeafPath(root->left, n+1);
	rootToLeafPath(root->right, n+1);
	return;
}

void printKNodes(node* root, int k)
{
	if(!root)
		return;

	if(k==0)
	{
		printf("%d ", root->data);
		return;
	}
	printKNodes(root->left, k-1);
	printKNodes(root->right, k-1);
	return;
}

int printNodes1dist(node* root)
{
	if(!root)
		return 0;

	if( (!root->left) && (!root->right))
		return 1;
	
	if( printNodes1dist(root->left) || printNodes1dist(root->right))
		printf("%d ", root->data);

	return 0;
}


int main()
{
	treeNode *root = NULL;
	insertBST(&root, 6, NULL);	//				6
	insertBST(&root, 4);		//		4						
	insertBST(&root, 9);		//						9	
	insertBST(&root, 5);		//			5		   
	insertBST(&root, 8);		//					8
	insertBST(&root, 7);		//				   7	
	insertBST(&root, 7);		//					 7
	printInOrder(root);
	
	printf("\n Max Height = %d",height(root));
	printf("\n isBalanced = %d",isBalanced(root));
	printf("\n min = %d",getMin(root));
	printf("\n max = %d",getMax(root));

	printf("\n");
	// deleteBST(&root, 7);

	// deleteBST(&root, 5);
	// printf("\n after deleting\n");
	// printInOrder(root);

	// printf("\n Max Height = %d",height(root));
	// printf("\n isBalanced = %d",isBalanced(root));
	// printf("\n min = %d",getMin(root));
	// printf("\n max = %d",getMax(root));

	// printf("\n");
	printf("\nbalancedTreeFromArray({1,2,3,4,5,6,7})\n");
	int arr[] = {1,2,3,4,5,6,7};
	node* newRoot = balancedTreeFromArray(arr,0,6);
	printInOrder(newRoot);
	// printf("\n Max Height = %d",height(newRoot));
	// printf("\n isBalanced = %d",isBalanced(newRoot));
	// printf("\n min = %d",getMin(newRoot));
	// printf("\n max = %d",getMax(newRoot));

	printf("\n");
	// printf("\ngetSuccessor(4) : %d", (newRoot)->data);
	// printf("\ngetSuccessor(3) : %d", getSuccessor(newRoot->left->right)->data);
	// printf("\ngetSuccessor(4) : %d", getSuccessor(newRoot)->data);
	// printf("\ngetSuccessor(5) : %d", getSuccessor(newRoot->right->left)->data);
	// printf("\ngetSuccessor(6) : %d", getSuccessor(newRoot->right)->data);

	// rootToLeafPath(newRoot);
	// printKNodes(root, 2);
	// printf("\n");
	// printKNodes(root, 3);
	// printf("\n");

	printNodes1dist(root);
	return 0;
}

