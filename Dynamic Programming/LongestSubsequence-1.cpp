using namespace std;
#include<bits/stdc++.h>
int longestSubsequence(int N, int A[])
{
    int dp[N];
    for (int i = 0; i < N; i++)
    {
        dp[i] = 1;
    }
    for (int i = 1; i < N; i++)
    {
        int m = 0;
        for (int j = 0; j < i; j++)
        {
            if (abs(A[i] - A[j]) == 1)
            {
                m = max(m, dp[j]);
            }
            dp[i] = m + 1;
        }
    }
    int maxi = 0;
    for (int i = 0; i < N; i++)
    {
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}
int main()
{
    int arr[5]={1,2,3,4,5};
    cout<<longestSubsequence(5,arr)<<"\n";
}