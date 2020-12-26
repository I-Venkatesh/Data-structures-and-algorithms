#include <iostream>
using namespace std;

int main() {
	//code
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
	    int left[num];
	    int right[num];
	    int maxi=arr[0];
	    left[0]=0;
	    for(int i=1;i<num;i++)
	    {
	        left[i]=maxi;
	        maxi=max(maxi,arr[i]);
	    }
	    right[num-1]=0;
	    maxi=arr[num-1];
	    for(int i=num-2;i>=0;i--)
	    {
	        right[i]=maxi;
	        maxi=max(arr[i],maxi);
	    }
	    long long int ans=0;
	    for(int i=1;i<num-1;i++)
	    {
	        if(min(left[i],right[i])-arr[i]>0)
	        {
	            ans+=min(left[i],right[i])-arr[i];
	        }
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}