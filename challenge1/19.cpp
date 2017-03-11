#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d" , &n);
	while(n--)
	{
	    char s[1000];
	    scanf("%s", s);

        int c=0;
        int l =strlen(s)-1;


		// for (int i = 0; i < (l+1)/2; i++)
  //       	{
  //       		printf("%c%c\n", s[i], s[l-i]);
  //       	}

        if(strlen(s) & 1)
        	c=0;

        else
        {
        	for (int i = 0; i < (l+1)/2; i++)
        	{
    	       if( (s[i]=='{' && s[l-i]=='}') || 
                            (s[i]=='(' && s[l-i]==')') || 
                                    (s[i]=='[' && s[l-i]==']') ||

                    (s[i]=='}' && s[l-i]=='{') || 
                        (s[i]==')' && s[l-i]=='(') || 
                                (s[i]==']' && s[l-i]=='[') ||

                    (s[i]=='{' && s[l-i]=='{') || 
                            (s[i]=='(' && s[l-i]=='(') || 
                                    (s[i]=='[' && s[l-i]=='[') ||

                    (s[i]=='}' && s[l-i]=='}') || 
                            (s[i]==')' && s[l-i]==')') || 
                                    (s[i]==']' && s[l-i]==']') )
    			    c++;
        	}
        }   

        if(c == strlen(s)/2)
        	printf("YES\n");
        else
        	printf("NO\n"); 
	}
	return 0;
}




/**********************************/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct stackNode
{
    char data;
    struct node* st;
};

int ArePair(char opening,char closing)
{
    if(opening == '(' && closing == ')') 
        return 1;
    else if(opening == '{' && closing == '}') 
        return 1;
    else if(opening == '[' && closing == ']') 
        return 1;
    return 0;
}


int isBalanced(string s)
{

    for (int i = 0; s[i]!='\0'; i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            //push

        else if(s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if//stack is empty || !isPair(top, s[i])
                return 0;
            else
                //pop
        }
    }
    if//(stack is empty )
        return 1;
    return 0
}


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string s;
        cin >> s;

        cout << if(isBalanced(s)) ? "YES" : "NO";
    }
    return 0;
}
