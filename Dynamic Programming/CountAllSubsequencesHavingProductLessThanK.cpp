using namespace std;
#include<bits/stdc++.h>
int dp[100][100];
int countSub(int arr[],int k,int num)
{
    for(int i=0;i<=num;i++)
    {
        for(int j=0;j<=k;j++)
        {
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=num;i++)
    {
        for(int j=1;j<=k;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(arr[i-1]<=j&&arr[i-1]>=0)
            {
                dp[i][j]+=dp[i-1][j/arr[i-1]]+1;
            }
        }
    }
    return dp[num][k];
}
int main()
{
    memset(dp,0,sizeof(dp));
    int arr[4]={1,2,3,4};
    int k=10;
    cout<<countSub(arr,k,4);
}