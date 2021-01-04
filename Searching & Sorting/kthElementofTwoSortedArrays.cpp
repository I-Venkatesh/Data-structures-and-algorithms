#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin>>test;
	while(test--)
	{
	    int n,m,k;
	    cin>>n>>m>>k;
	    int arr1[n];
	    int arr2[m];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr1[i];
	    }
	    for(int i=0;i<m;i++)
	    {
	        cin>>arr2[i];
	    }
	    int i=0,j=0,flag=0;
	    while(i<n&&j<m&&flag<k)
	    {
	        if(arr1[i]<arr2[j])
	        {
	            flag++;
	            if(flag==k)
	            {
	                cout<<arr1[i]<<"\n";
	                break;
	            }
	            i++;
	        }
	        else{
	            flag++;
	            if(flag==k)
	            {
	                cout<<arr2[j]<<"\n";
	                break;
	            }
	            j++;
	        }
	    }
	    while(i<n&&flag<k)
	    {
	        flag++;
	        if(flag==k)
	        {
	            cout<<arr1[i]<<"\n";
	            break;
	        }
	        i++;
	        
	    }
	    while(j<m&&flag<k)
	    {
	        
	        flag++;
	        if(flag==k)
	        {
	            cout<<arr2[j]<<"\n";
	            break;
	        }
	        j++;
	    }
	    
	}
	return 0;
}