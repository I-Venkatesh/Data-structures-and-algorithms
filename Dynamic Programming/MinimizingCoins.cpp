using namespace std;
#include<bits/stdc++.h>
int dp[1000009];
int arr[1005];
int n,sum;
int calc(int sum)
{
    if(sum<0)
    {
        return -1;
    }
    if(sum==0)
    {
        return 0;
    }
    if(dp[sum]!=0)
    {
        return dp[sum];
    }
    int mini=INT_MAX;
    for(int i=0;i<n;i++)
    {
        int res=calc(sum-arr[i]);
        if(res>=0&&res<mini)
        {
            mini=1+res;
        }
    }
    dp[sum]=(mini==INT_MAX)?-1:mini;
    return dp[sum];
}

int main()
{
    cin>>n>>sum;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=calc(sum);
    cout<<ans<<"\n";
}