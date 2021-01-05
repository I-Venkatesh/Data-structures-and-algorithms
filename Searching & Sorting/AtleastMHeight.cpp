#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	test=1;
	while(test--)
	{
	    long long int n,h;
        cin>>n>>h;
        long long int arr[n];
        long long int l=0,r=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            r=max(r,arr[i]);
        }
        sort(arr,arr+n);
        long long int ans,sum=0;
        while(l+1<r)
        {
            long long int mid=(l+(r-l)/2);
            sum=0;
            for(int i=0;i<n;i++)
            {
                if(arr[i]-mid>0)
                {
                    sum+=arr[i]-mid;
                }
            }
            if(sum>=h)
            {
                l=mid;
                ans=mid;
            }
            else{
                r=mid;
            }
        }
        cout<<ans<<"\n";
	}
	return 0;
}