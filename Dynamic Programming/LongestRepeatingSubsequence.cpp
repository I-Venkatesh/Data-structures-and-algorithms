using namespace std;
#include <bits/stdc++.h>
int dp[1000][1000];
int LongestRepeatingSubsequence(string str)
{
    // Code here
    int dp[str.length() + 1][str.length() + 1];
    for (int i = 0; i <= str.length(); i++)
    {
        for (int j = 0; j <= str.length(); j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (i == j && str[i - 1] == str[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (str[i - 1] == str[j - 1] && i != j)
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= str.length(); i++)
    {
        for (int j = 0; j <= str.length(); j++)
        {
            //  cout<<dp[i][j]<<" ";
            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}
int main()
{
    int a = 6;
    string str = "axxxy";
    cout << LongestRepeatingSubsequence(str) << "\n";
}