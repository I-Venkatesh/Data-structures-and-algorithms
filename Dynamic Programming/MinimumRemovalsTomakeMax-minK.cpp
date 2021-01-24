using namespace std;
#include<bits/stdc++.h>
int dp[1000][1000];
int solve(int arr[],int i,int j,int k)
{
    if(i>=j)
    {
        return 0;
    }
    else if(arr[j]-arr[i]<=k)
    {
        return 0;
    }
    else if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    else if(arr[j]-arr[i]>k)
    {
        dp[i][j]=1+min(solve(arr,i+1,j,k),solve(arr,i,j-1,k));
    }
    return dp[i][j];

}
int main()
{
    int arr[9]={1,3,4,9,10,11,12,17,20};
    int k=4;
    sort(arr,arr+9);
    memset(dp,-1,sizeof(dp));
    cout<<solve(arr,0,8,k);
}