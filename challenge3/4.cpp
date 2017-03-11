/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/

// int height(Node* root)
// {
// 	if(!root)
// 		return 0;

// 	int l = height(root->left);
// 	int r = height(root->right);

// 	return (1 + (l>=r)? l: r);
// }

// bool checkbalance(Node* root) 
// {
// 	if(!root)
// 		return true;
// 	int lh = height(root->left);
// 	int rh = height(root->right);
	
// 	if( abs(lh-rh)<2 && checkbalance(root->left) && checkbalance(root->right) && 
// 			root->left->data < root->data)
// 		return true;

// 	return false;
// }



bool checkBSTTemp(Node* root, int min, int max) 
{
	if(!root)
		return 1;

	if(root->data <= min || root->data >= max)
		return 0;

	return (checkBSTTemp(root->left, min, root->data) && 
					checkBSTTemp(root->right, root->data, max) );
}


bool checkBST(Node* root)
{
	return (checkBSTTemp(root, 	-9999999, 9999999));
}