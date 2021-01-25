#include<bits/stdc++.h>
using namespace std;
long long int dp[1000][1000];
long long int ans(int arr[],int i,int j)
{
    if(i+1==j)
    {
        return max(arr[j],arr[i]);
    }
    if(i==j)
    {
        return arr[i];
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    return dp[i][j]=max(arr[i]+min(ans(arr,i+2,j),ans(arr,i+1,j-1)),arr[j]+min(ans(arr,i+1,j-1),ans(arr,i,j-2)));
}
long long maximumAmount(int arr[], int n) 
{
    memset(dp,-1,sizeof(dp));
    long long int t=ans(arr,0,n-1);
    return t;
}
int main()
{
    int num;
    cin>>num;
    int arr[num];
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    cout<<maximumAmount(arr,num)<<"\n";
}