#include <iostream>
using namespace std;

struct trieNode
{
	int isWord;
	struct trieNode* child[26];
	int wordCount;
};
typedef struct trieNode node;

node* createNewNode()
{
	node* newNode = new node;
	for (int i = 0; i < 26; i++)
		newNode->child[i] = NULL;
	newNode->isWord = 0;
	newNode->wordCount = 0;
	
	return newNode;
}

void insert(node* root, char* str)
{
	for (int i = 0; str[i]!='\0'; i++)
	{
		int ch = str[i] - 'a';
		if(!(root->child[ch]))
			root->child[ch] = createNewNode();
		
		(root->wordCount)++;
		root = root->child[ch];
	}
	root->isWord = 1;
}

int search(node* root, char* str)
{
	for (int i = 0; str[i]!='\0'; i++)
	{
		int ch = str[i] - 'a';
		if(!(root->child[ch]))
			return 0;
		root = root->child[ch];
	}
	return (root->isWord);
}

int prefixCount(node* root, char* str)
{
	for (int i = 0; str[i]!='\0'; i++)
	{
		int ch = str[i] - 'a';
		if(!(root->child[ch]))
			return 0;
		root = root->child[ch];
	}
	return (root->wordCount);
}

// int autoComplete(node* root, char* str)
// {
// 	for (int i = 0; str[i]!='\0'; i++)
// 	{
// 		int ch = str[i] - 'a';
// 		if(!(root->child[ch]))
// 			return 0;
// 		root = root->child[ch];
// 	}
	
// 	if(root->wordCount == 1)
// 	{
//		cout << str;
// 		while(root->isWord != 1)
// 		{
// 			for (int i = 0; i<26; ++i)
// 			{
// 				if((root->child[i]))
// 				{
// 					cout << char('a'+i);
// 					root = root->child[i];
// 				}	
// 			}
// 		}
// 		return 1;
// 	}
// 	return 0;
// }

void autoComplete(node* root, char* str)
{
	for (int i = 0; str[i]!='\0'; i++)
	{
		int ch = str[i] - 'a';
		if(!(root->child[ch]))
			return ;
		root = root->child[ch];
	}
	
	if(root->wordCount == 1)
	{
		cout << str;
		while(root->isWord != 1)
			for (int i = 0; i<26; ++i)
				if((root->child[i]))
				{
					cout << char('a'+i);
					root = root->child[i];
				}	
	}
	return ;
}

int main()
{
	char str[][15] = {"algo", "algorithm", "all", "assoc", "tree", "trie"};
	node* root = createNewNode();

	for(int i=0; i<6; i++)
	{
		cout << str[i] << " ";
		insert(root, str[i]);
	}

	cout << search(root, "al") << endl;
	cout << search(root, "algol") << endl;
	cout << search(root, "all") << endl;
	cout << prefixCount(root, "al") << endl;
	// cout << autoComplete(root, "algori") << endl;
	autoComplete(root, "algori");
	cout << endl;
		
	return 0;
}





