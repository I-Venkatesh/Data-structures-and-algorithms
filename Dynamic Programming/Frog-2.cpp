using namespace std;
#include<bits/stdc++.h>
int num,k;
int arr[100005];
int dp[100005];
int recur(int curr)
{
    if(curr==num-1)
    {
        return 0;
    }
    if(curr>=num)
    {
        return INT_MAX;
    }
    if(dp[curr]!=-1)
    {
        return dp[curr];
    }
    int mini=INT_MAX;
    int x[k];
    for(int i=0;i<k;i++)
    {
        x[i]=INT_MAX;
    }
    for(int i=1;i<=k;i++)
    {
        if(curr+i<num)
        {
            x[i-1]=(mini,abs(arr[curr]-arr[curr+i]))+recur(curr+i);
        }
    }
    for(int i=0;i<min(k,num);i++)
    {
        mini=min(mini,x[i]);
    }
    return dp[curr]=mini;
}
int main()
{
    cin>>num>>k;
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<recur(0);
}