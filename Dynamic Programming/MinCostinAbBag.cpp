using namespace std;
#include<bits/stdc++.h>

int minimumCost(int cost[], int n, int W)
{
    long long int dp[n + 1][W + 1];
    for (int i = 0; i <= W; i++)
    {
        dp[0][i] = INT_MAX;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (i <= j && cost[i - 1] != -1)
            {
                dp[i][j] = min(dp[i - 1][j], cost[i - 1] + dp[i][j - i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    if (dp[n][W] == INT_MAX)
    {
        return -1;
    }
    return dp[n][W];
}
int main()
{
    int n=5;
    int arr[5]={20,10,4,50,100};
    int W=5;
    cout<<minimumCost(arr,n,W);
}