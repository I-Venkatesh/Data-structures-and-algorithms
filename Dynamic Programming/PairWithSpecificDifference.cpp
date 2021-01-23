#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin>>test;
	while(test--)
	{
	    int num,k;
	    cin>>num;
	    int arr[num];
	    for(int i=0;i<num;i++)
	    {
	        cin>>arr[i];
	    }
	    cin>>k;
	    sort(arr,arr+num);
	    int sum=0;
	    for(int i=num-1;i>0;i--)
	    {
	        if(arr[i]-arr[i-1]<k)
	        {
	           // cout<<arr[i]<<" "<<arr[i-1]<<" ";
	            sum+=arr[i]+arr[i-1];
	            i--;
	        }
	    }
	    cout<<sum<<"\n";
	}
	return 0;
}