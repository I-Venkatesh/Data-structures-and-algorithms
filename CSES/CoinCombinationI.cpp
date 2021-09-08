#include <bits/stdc++.h>
using namespace std;
int dp[1000005];
int solve(int* arr,int n,int target)
{
    if(target==0) return 1;
    if(target<0) return 0;
    if(dp[target]!=-1) {
        return dp[target];
    }
    int ans=0;
    for(int i=0;i<n;i++) {
        ans=(ans+solve(arr,n,target-arr[i]))%1000000007;
    }
    return dp[target]=ans%1000000007;
}
int main()
{
    int n,target;
    memset(dp,-1,sizeof(dp));
    cin>>n>>target;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=solve(arr,n,target);
    cout<<ans<<"\n";
}