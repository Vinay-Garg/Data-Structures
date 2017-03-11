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


int main(){
    int n;
    int k;
    int q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    
    k=k%n;
 //    int temp;
	// for(int i=0; i<k; i++) 
	// {
 //   	temp = a[n-1];
 //  	for(int q=n-1;q>=1;q--)
 //       a[q]=a[q-1];
 //    a[0]=temp;
	// }
    int l = sizeof(a)/ sizeof(a[0]);
	for(int i=0; i<q; i++)
	{
		int m;
   		cin >> m;
   		
        cout << a[(n-k+m)%n] << endl;            
	}

    return 0;
}
