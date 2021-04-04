using namespace std;
#include<bits/stdc++.h>
long long int arr[1000005];
long long int dp[1000005];
long long int n,s;
long long int calc(long long int s)
{
    if(s<0)
    {
        return 0;
    }
    if(s==0)
    {
        return 1;
    }
    if(dp[s]!=-1)
    {
        return dp[s];
    }
    long long int maxi=0;
    for(int i=0;i<n;i++)
    {
        maxi+=(calc(s-arr[i])%1000000007);
    }
    return dp[s]=maxi%1000000007;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n>>s;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<calc(s)<<"\n";
}