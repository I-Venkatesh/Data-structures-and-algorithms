class Solution {
public:
    int dp[201][201];
    int X[4]={0,1,-1,0};
    int Y[4]={1,0,0,-1};
    int valid(int x,int y,int m,int n)
    {
        if(x>=0&x<m&&y>=0&&y<n)
        {
            return 1;
        }
        return 0;
    }
    int calc(vector<vector<int>>& matrix,int x,int y)
    {
        if(dp[x][y]!=-1)
        {
            return dp[x][y];
        }
        int maxi=0;
        for(int i=0;i<4;i++)
        {
            if(valid(x+X[i],y+Y[i],matrix.size(),matrix[0].size()))
            {
                int curr=matrix[x][y];
                int next=matrix[x+X[i]][y+Y[i]];
                if(next>curr)
                {
                   maxi=max(maxi,1+calc(matrix,x+X[i],y+Y[i])); 
                }
            }
        }
        return dp[x][y]=maxi;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof(dp));
        int maxi=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                maxi=max(maxi,1+calc(matrix,i,j));
            }
        }
        return maxi;
    }
};