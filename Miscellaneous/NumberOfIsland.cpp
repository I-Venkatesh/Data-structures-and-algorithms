class Solution {
public:
    int visited[301][301];
    int X[4]={0,1,-1,0};
    int Y[4]={1,0,0,-1};
    bool valid(vector<vector<char>>& grid,int i,int j,int x,int y)
    {
        if(i>=0&&i<x&&j>=0&&j<y&&visited[i][j]==0&&grid[i][j]=='1')
        {
            visited[i][j]=1;
            return true;
        }
        return false;
    }
    void calc(vector<vector<char>>& grid, int i,int j)
    {
        for(int a=0;a<4;a++)
        {
            if(valid(grid,i+X[a],j+Y[a],grid.size(),grid[0].size()))
            {
                calc(grid,i+X[a],j+Y[a]);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(!visited[i][j]&&grid[i][j]=='1')
                {
                    ans++;
                    calc(grid,i,j);
                }
            }
        }
        return ans;
    }
};