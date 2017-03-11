/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/


void decode_huff(node * root,string s)
{
	node* temp = root;
	for (int i = 0; s[i]!='\0'; ++i)
	{
		if(s[i]=='0')
			temp = temp->left;
		else if(s[i]=='1')
			temp = temp->right;

		if(!temp->left && !temp->right)
		{
			printf("%c", temp->data);
			temp =root;
		}
	}
    
}
