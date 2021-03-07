#include <bits/stdc++.h>
using namespace std;
int main() {
	int num;
	cin >> num;
	int arr[num];
	for(int i=0;i<num;i++)
	{
		cin>>arr[i];
	}
	int prefix[num],suffix[num];
	int ans=1;
	prefix[0]=1;
	for(int i=1;i<num;i++)
	{
		if(arr[i]>arr[i-1])
		{
			prefix[i]=prefix[i-1]+1;
		}
		else{
			prefix[i]=1;
		}
		ans=max(ans,prefix[i]);
	}
	suffix[num-1]=1;
	for(int i=num-2;i>=0;i--)
	{
		if(arr[i]<arr[i+1])
		{
			suffix[i]=suffix[i+1]+1;
		}
		else{
			suffix[i]=1;
		}
		ans=max(ans,suffix[i]);
	}
	for(int i=1;i<num-1;i++)
	{
		if(arr[i-1]<arr[i+1])
		{
			ans=max(ans,prefix[i-1]+suffix[i+1]);
		}
	}
	cout<<ans<<"\n";
}

