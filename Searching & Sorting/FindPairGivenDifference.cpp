#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin>>test;
	while(test--)
	{
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    int freq[100005];
	    memset(freq,0,sizeof(freq));
	    bool ok=true;
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	        freq[arr[i]]++;
	    }
	    for(int i=0;i<n;i++)
	    {
	        freq[arr[i]]--;
	        int target=abs(k-arr[i]);
	        if(freq[target]>0)
	        {
	            cout<<1<<"\n";
	            ok=false;
	            break;
	        }
	        else{
	            freq[arr[i]]++;
	        }
	        
	    }
	    if(ok)
	    {
	        cout<<-1<<"\n";
	    }
	}
	return 0;
}