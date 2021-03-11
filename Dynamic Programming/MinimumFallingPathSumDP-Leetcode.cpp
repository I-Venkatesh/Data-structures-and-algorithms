class Solution {
public:
    int dp[101][101];
    int X[3]={1,1,1};
    int Y[3]={-1,0,1};
    bool valid(vector<vector<int>>& matrix,int i,int j)
    {
        int m=matrix.size();
        int n=matrix[0].size();
        if(i<m&&i>=0&&j<n&&j>=0)
        {
            return true;
        }
        return false;
    }
    int visited[101][101];
    int calc(vector<vector<int>>& matrix,int x,int y)
    {
        if(x==matrix.size()-1)
        {
            return matrix[x][y];
        }
        if(dp[x][y]!=-1)
        {
            return dp[x][y];
        }
        visited[x][y]=1;
        int sum=INT_MAX;
        for(int i=0;i<3;i++)
        {
            if(valid(matrix,x+X[i],y+Y[i])&&!visited[x+X[i]][y+Y[i]])
            {
                sum=min(sum,matrix[x][y]+calc(matrix,x+X[i],y+Y[i]));
                visited[x+X[i]][y+Y[i]]=0;
            }
        
        }
        return dp[x][y]=sum;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof(dp));
        int mini=INT_MAX;
        for(int i=0;i<matrix.size();i++)
        {
            mini=min(mini,calc(matrix,0,i));
        }
        return mini;
    }
};