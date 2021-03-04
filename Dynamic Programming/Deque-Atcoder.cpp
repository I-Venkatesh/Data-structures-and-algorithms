using namespace std;
#include<bits/stdc++.h>
#define ll long long int
ll dp[5001][5001];
int num;
ll arr[100005];
ll calc(int i,int j)
{
    if(i==j)
    {
        return arr[i];
    }
    if(i==(j-1))
    {
        return max(arr[i],arr[j]);
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    ll op1=arr[i]+min(calc(i+2,j),calc(i+1,j-1));
    ll op2=arr[j]+min(calc(i+1,j-1),calc(i,j-2));
    return dp[i][j]=max(op1,op2);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>num;
    ll sum=0;
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    ll f1=calc(0,num-1);
    ll f2=sum-f1;
    cout<<f1-f2;
}