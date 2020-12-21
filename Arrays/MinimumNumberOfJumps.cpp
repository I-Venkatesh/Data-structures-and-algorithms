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
        int mini[n];
        for(int i=0;i<n;i++)
        {
            mini[i]=100000009;
        }   
         mini[0]=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[j]+j>=i)
                {
                    mini[i]=min(mini[i],mini[j]+1);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            // cout<<mini[i]<<" ";
        }
        if(mini[n-1]==100000009)
        {
            cout<<-1<<"\n";
        }
        else
        {
            cout<<mini[n-1]<<"\n";
        }
        
	}
	return 0;
}