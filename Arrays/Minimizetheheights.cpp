using namespace std;
#include<bits/stdc++.h>
int main() {
	int test;
	test=1;
	while(test--)
	{
	    int n,k;
    	cin>>k>>n;
        int arr[n];
    	for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int small=arr[0]+k;
        int big=arr[n-1]-k;
        if(small>big)
        {
            swap(big,small);
        }
        int ans=big-small;
        for(int i=1;i<n-1;i++)
        {
            int add=arr[i]+k;
            int subtract=arr[i]-k;
            if(add<=big||subtract>=small)
            {
                continue;
            }
            if(add-small<big-subtract)
            {
                big=add;
            }
            else
            {
                small=subtract;
            }
            ans=min(ans,big-small);
        }
        cout<<ans<<"\n";
	}
	return 0;
}