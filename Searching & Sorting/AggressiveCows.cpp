#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin>>test;
	while(test--)
	{
	    int n,c;
        cin>>n>>c;
        long long int arr[n];
        long long int l=0,r;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            r=max(r,arr[i]);
        }
        sort(arr,arr+n);
        long long int ans;
        while(l<=r)
        {
            long long int mid=(l+r)/2;
            long long int hold=arr[0];
            int count=1;
            bool ok=false;
            for(int i=0;i<n;i++)
            {
                if(arr[i]-hold>=mid)
                {
                    hold=arr[i];
                    count++;
                }
                if(count==c)
                {
                    ok=true;
                    break;
                }
            }
            if(ok)
            {
                l=mid+1;
                ans=mid;
            }
            else{
                r=mid-1;
            }
        }
        cout<<ans<<"\n";
	}
	return 0;
}