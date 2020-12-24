#include <bits/stdc++.h>
using namespace std;
#define t 1e18+6;
int main() {
	//code
	int test;
	cin>>test;
	while(test--)
	{
	    long long int num;
	    cin>>num;
	    long long int arr[num];
	    for(int i=0;i<num;i++)
	    {
	        cin>>arr[i];
	    }
	    sort(arr,arr+num);
	    long long int m;
	    cin>>m;
	    long long int mini=t;
	    for(int i=0;i<=num-m;i++)
	    {
	        mini=min(mini,arr[i+m-1]-arr[i]);
	    }
	    cout<<mini<<"\n";
	}
	return 0;
}