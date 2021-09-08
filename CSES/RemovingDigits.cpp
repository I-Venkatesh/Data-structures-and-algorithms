#include <bits/stdc++.h>
using namespace std;
int dp[1000005];
int solve(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n<0)
    {
        return 1000000;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int temp=n;
    int ans=1000000;
    while(temp>0)
    {
        int rem=temp%10;
        if(rem!=0)
        {
            ans=min(ans,1+solve(n-rem));
        }
        temp/=10;
    }
    return dp[n]=ans;
}
int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<< solve(n);
}