class Solution {
public:
    int dp[201][201];
    bool valid(int i,int j,int r,int c)
    {
        if(i<0||i>=r||j<0||j>=c)
        {
            return false;
        }
        return true;
    }
    int calc(vector<vector<int>>& grid,int i,int j,int r,int c)
    {
        if(i==r-1&&j==c-1)
        {
            return grid[i][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int down=valid(i+1,j,r,c)==true ? grid[i][j]+calc(grid,i+1,j,r,c) : INT_MAX;
        int right=valid(i,j+1,r,c)==true ? grid[i][j]+calc(grid,i,j+1,r,c) : INT_MAX;
        return dp[i][j]=min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int mini=INT_MAX;
        memset(dp,-1,sizeof(dp));
        return calc(grid,0,0,grid.size(),grid[0].size());
    }
};