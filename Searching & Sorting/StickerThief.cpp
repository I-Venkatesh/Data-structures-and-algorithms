#include <bits/stdc++.h>
using namespace std;
int dp[100005];
int cal(int arr[],int n,int i)
{
    if(i==n-1)
    {
        return arr[i];
    }
    else if(i>=n)
    {
        return 0;
    }
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    else{
        return dp[i]=max(arr[i]+cal(arr,n,i+2),cal(arr,n,i+1));
    }
}
int main() {
	int test;
	cin>>test;
	while(test--)
	{
	    int num;
	    cin>>num;
	    int arr[num];
	    memset(dp,-1,sizeof(dp));
	    for(int i=0;i<num;i++)
	    {
	        cin>>arr[i];
	    }
	    cout<<cal(arr,num,0)<<"\n";
	}
	return 0;
}