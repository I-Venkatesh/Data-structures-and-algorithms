#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin>>test;
	while(test--)
	{
	    int num;
	    cin>>num;
	    int arr[num];
	    for(int i=0;i<num;i++)
	    {
	        cin>>arr[i];
	    }
	    int k,cnt=0;
	    cin>>k;
	    for(int i=0;i<num;i++)
	    {
	        if(arr[i]<=k)
	        {
	            cnt++;
	        }
	    }
	    int bad=0;
	    for(int i=0;i<cnt;i++)
	    {
	        if(arr[i]>k)
	        {
	            bad++;
	        }
	    }
	    int mini=bad;
	    for(int i=0;i<num-cnt;i++)
	    {
	        if(arr[i]>k)
	        {
	            bad--;
	        }
	        if(arr[i+cnt]>k)
	        {
	            bad++;
	        }
	        mini=min(mini,bad);
	    }
	    cout<<mini<<"\n";
	    
	}
	return 0;
}