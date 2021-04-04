using namespace std;
#include<bits/stdc++.h>
long long int dp[1000005];
int calc(int n)
{
    if(n==0)
    {
        return 1;
    }
    long long int ans=0;
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    for(int i=1;i<=6;i++)
    {
        if(n-i>=0)
        {
            ans+=calc(n-i)%1000000007;
        }
        else{
            break;
        }
    }
    return dp[n]=ans%1000000007;
}
int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<calc(n)%1000000007;
}