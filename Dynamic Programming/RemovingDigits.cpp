using namespace std;
#include<bits/stdc++.h>
int dp[1000005];
int calc(int num)
{
    if(num==0)
    {
        return 0;
    }
    if(num<0)
    {
        return 1000009;
    }
    if(dp[num]!=-1)
    {
        return dp[num];
    }
    vector<int> arr;
    int temp=num;
    while(temp>0)
    {
        arr.push_back(temp%10);
        temp/=10;
    }
    int mini=INT_MAX;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]!=0)
        {
            mini=min(mini,1+calc(num-arr[i]));
        }
    }
    return dp[num]=mini;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int num;
    cin>>num;
    cout<<calc(num)<<"\n";
}