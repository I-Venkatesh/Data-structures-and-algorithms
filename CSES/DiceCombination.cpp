using namespace std;
#include<bits/stdc++.h>
int dp[1000005];
int dice(int num)
{
    if(num==0) return 1;
    if(num<0) return 0;
    if(dp[num]!=-1)
    {
        return dp[num];
    }
    int ans=0;
    for(int i=1;i<=6;i++)
    {
        ans=(ans+dice(num-i))%1000000007;
    }
    return dp[num]=ans%1000000007;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int num;
    cin>>num;
    cout<<dice(num);
}