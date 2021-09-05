class Solution {
public:
    int visited[51][51];
    int X[4]={1,0,-1,0};
    int Y[4]={0,1,0,-1};
    int valid(vector<vector<int>>& grid,int i,int j)
    {
        if(i>=0&&i<grid.size()&&j>=0&&j<grid[0].size()&&visited[i][j]==0&&grid[i][j]==1)
        {
            return 1;
        }
        return 0;
    }
    int solve(vector<vector<int>>& grid,int x,int y)
    {
        visited[x][y]=1;
        int ans=0;
        for(int i=0;i<4;i++)
        {
            if(valid(grid,X[i]+x,Y[i]+y))
            {
                ans=ans+1+solve(grid,X[i]+x,Y[i]+y);
            }
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1&&visited[i][j]==0)
                {
                    ans=max(ans,1+solve(grid,i,j));
                }
            }
        }
        return ans;
    }
};