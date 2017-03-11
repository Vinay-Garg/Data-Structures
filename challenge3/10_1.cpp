#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct trieNode
{
	int isWord;
	struct trieNode* child[10];
};
typedef struct trieNode node;

node* createNewNode()
{
	node* newNode = new node;
	for (int i = 0; i < 10; i++)
		newNode->child[i] = NULL;
	newNode->isWord = 0;
	
	return newNode;
}

int insert(node* root, char* str)
{
	for (int i = 0; str[i]!='\0'; i++)
	{
		int ch = str[i] - 'a';
		if(!(root->child[ch]))
			root->child[ch] = createNewNode();

		else if(root->child[ch]->isWord)
			return 0;

		root = root->child[ch];
	}
	root->isWord = 1;
	return 1;
}

int main()
{
	node* root = createNewNode();
	int t,flag=0;
	cin >> t;
	char str[100][100];
	for (int i = 0; i < t; i++)
	{
		cin >> str[i];
		if(!insert(root, str[i]))
		{
            flag=1;
			cout << "BAD SET" << endl << str[i] << endl;
			return 0;
		}
	}        
        if(flag==0)
		cout << "GOOD SET" << endl;

	return 0;
}


