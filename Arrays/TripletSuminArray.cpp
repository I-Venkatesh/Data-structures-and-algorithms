#include <bits/stdc++.h>
using namespace std;
int main() {
	//code
	int test;
	cin>>test;
	while(test--)
	{
	    bool ok=false;
    	int n,x;
    	cin>>n>>x;
    	int arr[n];
    	int freq[100005];
    	memset(freq,0,sizeof(freq));
    	for(int i=0;i<n;i++)
    	{
    	    cin>>arr[i];
    	    freq[arr[i]]++;
    	}
    	sort(arr,arr+n);
    	for(int i=0;i<n;i++)
    	{
    	    int freq2[100005];
    	    for(int j=0;j<100005;j++)
    	    {
    	        freq2[j]=freq[j];
    	    }
    	    freq2[arr[i]]--;
    	    for(int j=i+1;j<n;j++)
    	    {
    	        freq2[arr[j]]--;
    	        int sum=arr[i]+arr[j];
    	        int left=x-sum;
    	        if(left>0)
    	        {
    	            if(freq2[left]>0)
    	            {
    	                ok=true;
    	                break;
    	            }
    	            freq2[arr[j]]++;
    	        }
    	    }
    	    if(ok)
    	    {
    	        break;
    	    }
    	}
    	if(!ok)
    	{
    	    cout<<0<<"\n";
    	}
    	else
    	{
    	    cout<<1<<"\n";
    	}
	}
	return 0;
}