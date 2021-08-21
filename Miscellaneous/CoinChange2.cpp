class Solution {
public:
    int dp[5001][301];
    int solve(int amt, vector<int>& coins,int curr)
    {
        if(amt<0||curr>=coins.size())
        {
            return 0;
        }
        if(amt==0)
        {
            return 1;
        }
        if(dp[amt][curr]!=-1)
        {
            return dp[amt][curr];
        }
        return dp[amt][curr]=solve(amt-coins[curr],coins,curr)+solve(amt,coins,curr+1);
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return solve(amount,coins,0);
    }
};