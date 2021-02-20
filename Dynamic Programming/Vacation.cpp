using namespace std;
#include<bits/stdc++.h>
vector<vector<int>> arr;
int n;
int dp[100005][3];
int func(int level,int x)
{
    if(level>=n)
    {
        return 0;
    }
    int left=INT_MIN,mid=INT_MIN,right=INT_MIN;
    if(dp[level][x]!=-1)
    {
        return dp[level][x];
    }
    if(x==0)
    {
        left=arr[level][x]+max(func(level+1,1),func(level+1,2));
    }
    if(x==1)
    {
        mid=arr[level][x]+max(func(level+1,0),func(level+1,2));
    }
    if(x==2)
    {
        right=arr[level][x]+max(func(level+1,0),func(level+1,1));
    }
    return dp[level][x]=max(left,max(mid,right));
}
int main()
{
    cin>>n;   
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        vector<int> temp;
        int x,y,z;
        cin>>x>>y>>z;
        temp.push_back(x);
        temp.push_back(y);
        temp.push_back(z);
        arr.push_back(temp);
    }
    cout<<max(func(0,0),max(func(0,1),func(0,2)));
}