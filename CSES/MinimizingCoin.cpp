#include <bits/stdc++.h>
using namespace std;
int dp[1000005];
int solve(int* arr,int n,int target)
{
    if(target==0) return 0;
    if(target<0) return 10000000;
    if(dp[target]!=-1) {
        return dp[target];
    }
    int ans=10000000;
    for(int i=0;i<n;i++) {
        ans=min(ans,1+solve(arr,n,target-arr[i]));
    }
    return dp[target]=ans;
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
    if(ans==10000000)
    {
        cout<<-1<<"\n";
    }else{
        cout<<ans<<"\n";
    }
}