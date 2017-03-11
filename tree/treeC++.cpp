#include <iostream>
#include <stdlib.h>
using namespace std;

struct treeNode
{
	int data;
	struct treeNode *left;
	struct treeNode *right;
};
typedef struct treeNode node;

node* createNewNode(int item, treeNode* left=NULL, treeNode* right=NULL)
{
	node* newNode = new node;
	newNode->data = item;
	newNode->left = left;
	newNode->right = right;
	return newNode;
}

void printInOrder(node* root)
{
	if(!root) return;
	printInOrder(root->left);
	cout << root->data<<" ";
	printInOrder(root->right);
}

void insertBST(node* &rootRef, int item)
{
	if(!rootRef) 
	{
		rootRef = createNewNode(item);
		return;
	}
	if(item < rootRef->data)
		insertBST(rootRef->left, item);
	else
		insertBST(rootRef->right, item);
}

node* getSuccessor(node* root)
{
	
}

node* findMinNode(node* root)
{
	if(!root) return NULL;
	while(root->left) 
		root = root->left;
	return root;
}

node* search(node* root, int item)
{
	if(!root || root->data==item)
		return root;
	if(item < root->data)
		return search(root->left, item);
	return search(root->right, item);
}

void deleteBST(node* &rootRef, int item)
{
	if(!rootRef) return;
	if(item < rootRef->data)
		deleteBST(rootRef->left, item);
	else if(item > rootRef->data)
		deleteBST(rootRef->right, item);
	else // target node found
	{
		if(!rootRef->left && !rootRef->right)
			delete rootRef;

		else if(!rootRef->left)
		{
			node* del = rootRef;
			rootRef = rootRef->right;
			delete del;
		}
		else if(!rootRef->right)
		{
			node* del = rootRef;
			rootRef = rootRef->left;
			delete del;
		}

		else
		{
			// mind min in right tree or max in left tree in temp
			// copy temp value in target node
			// since target node will have only one child 
			// delete temp
 			node* del = findMinNode(rootRef->right);
 			rootRef->data = del->data;
 			free(del);
 			// rootRef->right = del->right;
 			// deleteBST(rootRef->right, del->data); 
		}
	}
}

int height(node* root)
{
	if(!root) return 0;
	int lh = height(root->left);
	int rh = height(root->right);
	return (1 + ((lh>rh)? lh: rh));
}


int isBalanced(node* root)
{
	if(!root) return 1;
	int lh = height(root->left);
	int rh = height(root->right);
	return(abs(lh-rh)<2 && isBalanced(root->left) && isBalanced(root->right));
}


int getMax(node* root)
{
	if(!root) return -999999;
	int maxL = root->data;
	maxL = (getMax(root->left) > maxL)? getMax(root->left): maxL;
	int maxR = root->data;
	maxR = (getMax(root->right) > maxR)? getMax(root->right): maxR;
	return ( (maxL>maxR)? maxL: maxR );
}

int getMin(node* root)
{
	if(!root) return 999999;
	int minL = root->data;
	minL = (getMax(root->left) < minL)? getMax(root->left): minL;
	int minR = root->data;
	minR = (getMax(root->right) < minR)? getMax(root->right): minR;
	return ( (minL<minR)? minL: minR );
}

node* balancedTreeFromArray(int arr[], int start, int end)
{
	if(start > end) return NULL;
	int mid = (start+end) /2;
	node* newNode = createNewNode(arr[mid], 
					balancedTreeFromArray(arr, start, mid-1),
					balancedTreeFromArray(arr, mid+1, end));
	return newNode;
}

int main() {
	treeNode *root = NULL;
	insertBST(root, 6);
	insertBST(root, 4);
	insertBST(root, 9);
	insertBST(root, 5);
	insertBST(root, 8);
	insertBST(root, 7);
	insertBST(root, 7);
	printInOrder(root);
	
	cout << endl;
	cout << height(root);
	cout << "\n isBalanced = "<< isBalanced(root);
	cout << "\n min = "<<getMin(root);
	cout << "\n max = "<<getMax(root);

	cout << ("\n");
	deleteBST(root, 7);

	deleteBST(root, 5);
	cout << "\n after deleting\n";
	printInOrder(root);

	cout << "\n Max Height = "<<height(root);
	cout << "\n isBalanced = "<<isBalanced(root);
	cout << "\n min = "<<getMin(root);
	cout << "\n max = "<<getMax(root);

	cout << ("\n");
	cout << ("\nbalancedTreeFromArray({1,2,3,4,5,6,7})\n");
	int arr[] = {1,2,3,4,5,6,7};
	node* newRoot = balancedTreeFromArray(arr,0,6);
	printInOrder(newRoot);
	cout << "\n Max Height = "<<height(newRoot);
	cout << "\n isBalanced = "<<isBalanced(newRoot);
	cout << "\n min = "<<getMin(newRoot);
	cout << "\n max = "<<getMax(newRoot);

	// cout << ("\n");
	// cout << ("\ngetSuccessor(4) : %d", (newRoot)->data);
	// cout << ("\ngetSuccessor(3) : %d", getSuccessor(newRoot->left->right)->data);
	// cout << ("\ngetSuccessor(4) : %d", getSuccessor(newRoot)->data);
	// cout << ("\ngetSuccessor(5) : %d", getSuccessor(newRoot->right->left)->data);
	// cout << ("\ngetSuccessor(6) : %d", getSuccessor(newRoot->right)->data);

	cout << ("\n");
	return 0;
}

