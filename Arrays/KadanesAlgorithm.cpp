using namespace std;
#include<bits/stdc++.h>
int main() {
	int test;
	test=1;
	while(test--)
	{
	    int n;
    	cin>>n;
        int arr[n];
    	for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int curr=arr[0];
        int ans[n];
        ans[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            ans[i]=max(arr[i],ans[i-1]+arr[i]);
        }
        int maxi=-1000000009;
        for(int i=0;i<n;i++)
        {
            maxi=max(ans[i],maxi);
        }
        cout<<maxi<<"\n";
	}
	return 0;
}