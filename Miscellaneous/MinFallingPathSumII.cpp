class Solution {
public:
    int dp[201][201];
    int helper(int i,int j,vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i==n)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int mini=INT_MAX;
        for(int k=j+1;k<m;k++)
        {
            mini=min(mini,grid[i][k]+helper(i+1,k,grid));
        }
        for(int k=j-1;k>=0;k--)
        {
            mini=min(mini,grid[i][k]+helper(i+1,k,grid));
        }
        return dp[i][j]=mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            mini=min(mini,grid[0][i]+helper(1,i,grid));
        }
        return mini;
    }
};