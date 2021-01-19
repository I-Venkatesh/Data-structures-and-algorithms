using namespace std;
#include <bits/stdc++.h>
long long int dp[1000][1000];
long long int recur(int n, int S[], int i, int m)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0 || i >= m)
    {
        return 0;
    }
    if (dp[i][n] != -1)
    {
        return dp[i][n];
    }
    long long int left = recur(n - S[i], S, i, m);
    long long int right = recur(n, S, i + 1, m);
    return dp[i][n] = left + right;
}
long long int count(int S[], int m, int n)
{
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            dp[i][j] = -1;
        }
    }
    return recur(n, S, 0, m);
}
int main()
{
    int n = 4, m = 3;
    int arr[3] = {1, 2, 3};
    cout << count(arr,m,n);
}