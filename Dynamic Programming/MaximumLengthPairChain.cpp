#include <bits/stdc++.h>
using namespace std;
int dp[100005];
int findLongestChain(vector<vector<int>> &pairs)
{
    sort(pairs.begin(), pairs.end());
    int size = pairs.size();
    dp[0] = 1;
    for (int i = 1; i < size; i++)
    {
        dp[i] = 1;
        int m = 0;
        for (int j = 0; j < i; j++)
        {
            if (pairs[i][0] > pairs[j][1])
            {
                m = max(m, dp[j]);
            }
        }
        dp[i] = max(dp[i], m + 1);
    }
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = max(ans, dp[i]);
    }
    return ans;
}
int main()
{
    vector<vector<int>> pairs = {{1,2},{2,3},{3,4}};
    cout<<findLongestChain(pairs)<<"\n";
}