using namespace std;
#include<bits/stdc++.h>
int arr[100005];
int num;
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
    int left=abs(arr[curr]-arr[curr+1])+recur(curr+1);
    int right=INT_MAX;
    if(curr+2<num)
    {
        right=abs(arr[curr]-arr[curr+2])+recur(curr+2);
    }
    return dp[curr]=min(left,right);
}
int main()
{
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<recur(0);
}