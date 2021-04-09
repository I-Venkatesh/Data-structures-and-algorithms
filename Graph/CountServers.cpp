class Solution {
public:
    bool visited[251][251];
    int dfs(vector<vector<int>>& grid,int i,int j,int n,int m)
    {
        visited[i][j]=1;
        int right=0,down=0;
        for(int k=i;k<n;k++)
        {
            if(k+1<n&&!visited[k+1][j]&&grid[k+1][j]==1)
            {
                down=1+dfs(grid,k+1,j,n,m);
            }
        }
        for(int k=i;k>=0;k--)
        {
            if(k-1>=0&&!visited[k-1][j]&&grid[k-1][j]==1)
            {
                down=1+dfs(grid,k-1,j,n,m);
            }
        }
        for(int k=j;k<m;k++)
        {
            if(k+1<m&&!visited[i][k+1]&&grid[i][k+1]==1)
            {
                right=1+dfs(grid,i,k+1,n,m);
            }
        }
        for(int k=j;k>=0;k--)
        {
            if(k-1>=0&&!visited[i][k-1]&&grid[i][k-1]==1)
            {
                right=1+dfs(grid,i,k-1,n,m);
            }
        }
        return right+down;
    }
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j]&&grid[i][j]==1)
                {
                    int ans=dfs(grid,i,j,n,m);
                    count+=ans>0?ans+1:0;
                }
            }
        }
        return count;
    }
};