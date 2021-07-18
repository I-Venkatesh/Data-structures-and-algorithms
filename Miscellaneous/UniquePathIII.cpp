class Solution {
public:
    int visited[21][21];
    int ans=0;
    int X[4]={0,1,-1,0};
    int Y[4]={1,0,0,-1};
    bool valid(int x,int y,int m,int n)
    {
        if(x>=0&&x<m&&y>=0&&y<n)
        {
            return true;
        }
        return false;
    }
    void helper(int x,int y,vector<vector<int>>& grid)
    {
        if(grid[x][y]==2)
        {
            int z=0;
            for(int i=0;i<grid.size();i++)
            {
                for(int j=0;j<grid[0].size();j++)
                {
                    if(visited[i][j]==0&&grid[i][j]==0)
                    {
                        z++;
                    }
                }
            }
            if(z==0)
            {
                visited[x][y]=1;
                ans++;
                return;
            }
            else{
                visited[x][y]=1;
                return;
            }
        }
        visited[x][y]=1;
        for(int i=0;i<4;i++)
        {
            if(valid(X[i]+x,Y[i]+y,grid.size(),grid[0].size()))
            {  
                if(grid[X[i]+x][Y[i]+y]!=-1&&visited[X[i]+x][Y[i]+y]==0)
                {
                    helper(X[i]+x,Y[i]+y,grid);
                    visited[X[i]+x][Y[i]+y]=0;
                }
            }
        }
        return;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        memset(visited,0,sizeof(visited));
        int x,y,zero=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    x=i;
                    y=j;
                }
            }
        }
        // cout<<x<<" "<<y<<"\n";
        helper(x,y,grid);
        return ans;
    }
};