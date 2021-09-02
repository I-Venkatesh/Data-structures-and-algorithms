class Solution {
public:
    int visited[101][101];
    int X[4]={1,0,-1,0};
    int Y[4]={0,1,0,-1};
    int ans=0;
    int valid(int x,int y,int m,int n)
    {
        if(x>=0&&x<m&&y>=0&&y<n)
        {
            return 1;
        }
        return 0;
    }
    void solve(vector<vector<int>>& grid,int x,int y)
    {
        visited[x][y]=1;
        int water=0;
        for(int i=0;i<4;i++)
        {
            if(valid(x+X[i],y+Y[i],grid.size(),grid[0].size())&&grid[x+X[i]][y+Y[i]]==0)
            {
                water++;  
            }
            else if(!valid(x+X[i],y+Y[i],grid.size(),grid[0].size())){
                water++;
            }
        }
        if(water>0)
        {
            ans+=water;
        }
        for(int i=0;i<4;i++)
        {
            if(valid(x+X[i],y+Y[i],grid.size(),grid[0].size())&&visited[x+X[i]][y+Y[i]]==0&&grid[x+X[i]][y+Y[i]]==1)
            {
                solve(grid,x+X[i],y+Y[i]);
            }
        }
        return;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        memset(visited,0,sizeof(visited));
        int x=-1,y=-1;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    x=i;
                    y=j;
                }
                else{
                    visited[i][j]=1;
                }
            }
        }
        cout<<x<<" "<<y;
        solve(grid,x,y);
        return ans;
    }
};