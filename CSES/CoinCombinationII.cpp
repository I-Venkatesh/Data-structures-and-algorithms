#include <bits/stdc++.h>
using namespace std;
// int dp[1000001][101];
// int solve(int* arr,int n,int target,int curr)
// {
//     if(target<0||curr>=n) return 0;
//     if(target==0) return 1;
//     if(dp[target][curr]!=-1) {
//         return dp[target][curr];
//     }
//     int ans=0;
//     int inc=solve(arr,n,target-arr[curr],curr)%1000000007;
//     int ex=solve(arr,n,target,curr+1)%1000000007;
//     return dp[target][curr]=(inc+ex)%1000000007;
// }
int main()
{
    int n,target;
    // memset(dp,-1,sizeof(dp));
    cin>>n>>target;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    // int ans=solve(arr,n,target,0);
    int dp[n+1][target+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=target;j++)
        {
            if(j==0)
            {
                dp[i][j]=1;
            }
            else{
                if(j-arr[i-1]>=0)
                {
                    dp[i][j]=(dp[i][j-arr[i-1]]+dp[i-1][j])%1000000007;
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    }
    cout<<dp[n][target]%1000000007<<"\n";
}