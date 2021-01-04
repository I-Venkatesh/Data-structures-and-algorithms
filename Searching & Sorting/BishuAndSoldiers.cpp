#include <bits/stdc++.h>
using namespace std;
int bin(vector<int> arr,int n,int target)
{
	int l=0,r=n;
	int ans=-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(arr[mid]<=target)
		{
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return ans;
}
int main()
{
    int test;
    test=1;
    while (test--)
    {
        int num;
        cin >> num;
        vector<int> arr(num);
		long long int prefix[num];
		long long int s=0;
		for(int i=0;i<num;i++)
		{
			cin>>arr[i];
		}
		sort(arr.begin(),arr.end());
		for(int i=0;i<num;i++)
		{
			s+=arr[i];
			prefix[i]=s;
		}
		int q;
		cin>>q;
		for(int i=0;i<q;i++)
		{
			int n;
			cin>>n;
			int ans=bin(arr,num-1,n);
			cout<<ans+1<<" "<<prefix[ans]<<"\n";
		}
    }
    return 0;
}