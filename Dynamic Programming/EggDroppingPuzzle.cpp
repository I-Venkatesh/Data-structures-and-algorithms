using namespace std;
#include<bits/stdc++.h>
int dp[100][100];
int solve(int n,int k)
{
    if(k==0||k==1)
    {
        return k;
    }
    if(n==1)
    {
        return k;
    }
    if(dp[n][k]!=-1)
    {
        return dp[n][k];
    }
    int mini=INT_MAX;
    for(int x=1;x<=k;x++)
    {
        int t=1+max(solve(n-1,x-1),solve(n,k-x));
        mini=min(t,mini);
    }
    return dp[n][k]=mini;
}
int main()
{
    int n,k;
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    cout<<solve(n,k)<<"\n";
}