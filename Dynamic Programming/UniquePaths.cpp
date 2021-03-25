class Solution {
public:
    int dp[101][101];
    bool valid(int i,int j,int m,int n)
    {
        if(i<0||i>=m||j<0||j>=n)
        {
            return false;
        }
        return true;
    }
    int calc(int i,int j,int m,int n)
    {
        if(i==m-1&&j==n-1)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int down=0,right=0;
        if(valid(i+1,j,m,n))
        {
            down=calc(i+1,j,m,n);
        }
        if(valid(i,j+1,m,n))
        {
            right=calc(i,j+1,m,n);
        }
        return dp[i][j]=down+right;
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return calc(0,0,m,n);
    }
};