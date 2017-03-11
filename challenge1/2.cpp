#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,d;
    int temp;
    cin >> n >> d;
    int arr[n];
    
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    // for(int i=1; i<=d; i++)
    // {
    //     temp = arr[0];
    //     for(int j=0; j<n-1; j++)
    //         arr[j]=arr[j+1];
    //     arr[n-1]=temp ;
    // }

    for(int i=0; i<n; i++)
        cout << arr[(i+d) % n] << " ";

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
