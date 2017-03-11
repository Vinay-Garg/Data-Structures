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

int isPair(char opening,char closing)
{
	if(opening == '(' && closing == ')') 
		return 1;
	else if(opening == '{' && closing == '}') 
		return 1;
	else if(opening == '[' && closing == ']') 
		return 1;
	return 0;
}


int isBalanced(string str)
{
	stack<char> st; //make new  stack of char
	for (int i = 0; str[i]!='\0'; i++)
	{
		if(str[i]=='(' || str[i]=='{' || str[i]=='[')
			st.push(str[i]);

		else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
			if( st.empty() || !isPair(st.top(), str[i]) )
				return 0;
			else
				st.pop();
		}
	}
	if(st.empty())
		return 1;
	return 0;
}


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string s;
        cin >> s;

    if(isBalanced(s)) 
        cout << "YES" << endl;
    else
    cout << "NO" << endl;
    }
    return 0;
}
