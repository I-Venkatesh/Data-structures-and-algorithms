using namespace std;
#include <bits/stdc++.h>
int check(int N, int *arr, int s)
{
    bool dp[N + 2][s + 2];
    for (int i = 0; i <= s; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (j - arr[i - 1] >= 0)
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[N][s];
}
int equalPartition(int N, int arr[])
{
    long long int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
    }
    if (sum % 2 != 0)
    {
        return 0;
    }
    else
    {
        sum /= 2;
        if (check(N, arr, sum))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
int main()
{
    int n = 4;
    int arr[4] = {1, 5, 11,5};
    cout << equalPartition(n,arr);
}