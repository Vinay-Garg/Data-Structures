#include <cmath>
#include <stack>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
	int t, key, k;
	string str, w, temp;
	stack<string> st;
	cin >> t;
	while(t--)
	{
		cin >> key;

		if(key==1)
		{
			cin >> w;
			st.push(str);
			str = str +w;
		}

		if(key==2)
		{
			cin >> k;
			st.push(str);
			// str[str.length()-1 - k] = '\0';
			temp=str;   
            str="";
            str.append(temp,0,temp.length()-k);
		}

		if(key==3)
		{
			cin >> k;
			cout << str[k-1] << endl;
		}

		if(key==4)
		{
			str = st.top();
			st.pop();
		}
	}
    return 0;
}
