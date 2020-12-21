using namespace std;
#include<bits/stdc++.h>
int main() {
	int test;
	cin>>test;
	while(test--)
	{
	    int n;
    	cin>>n;
        int arr[n];
    	for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int f=arr[0];
        int e=arr[n-1];
        for(int i=n-1;i>0;i--)
        {
            arr[i]=arr[i-1];
        }
        arr[0]=e;
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
	}
	return 0;
}