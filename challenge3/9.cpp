 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

struct trieNode
{
	struct trieNode* child[26];
	int isWord;
	int wordCount;
};
typedef struct trieNode node;

node* createNewNode()
{
	node* newNode = (node*)malloc(sizeof(node));
	for (int i = 0; i < 26; i++)
		newNode->child[i] = NULL;
	newNode->isWord = 0;
	newNode->wordCount = 0;
	return newNode;
}

void insert(node* root, char* str)
{
	for (int i = 0; str[i]!='\0'; ++i)
	{
		int ch = str[i] - 'a';
		if(!root->child[ch])
			root->child[ch] = createNewNode();

		root->wordCount++;
		root = root->child[ch];
	}
	root->isWord = 1;
}


void prefixCount(node* root, char* str)
{
	
	for(int i=0; str[i] != '\0'; i++)
	{
		int ch = str[i]-'a';
		if(root->child[ch] == NULL)
		{
			printf("0\n");
			return ;
		}

		root = root->child[ch];	
	}
	printf("%d\n", root->wordCount);
}


int strSame(char* str1, char* str2)
{
	int flag = 0;
	while(*str1 == *str2)
	{
		if(*str1 =='\0')
		{
			flag = 1;
			break;
		}
		*str1++;
		*str2++;
	}
	if(flag)
		return 1;
	else
		return 0;
}


int main()
{
	node* root = createNewNode();
	int t;
	scanf("%d", &t);
	char str[1000], func[5];
	char add[5] = "add";
	char find[5]  ="find";

	while(t--)
	{
		scanf("%s %s", func, str);
		if(strSame(func, add))
			insert(root, str);

		if(strSame(func, find))
			prefixCount(root, str);
	}	
	return 0;
}
