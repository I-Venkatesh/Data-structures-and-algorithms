class Solution {
public:
    int ans;
    int visited[10][10];
    bool valid(int row,int col,int n)
    {
        for(int i=0;i<col;i++)
        {
            if(visited[row][i]==1)
            {
                return false;
            }
        }
        for(int i=row,j=col;i>=0&&j>=0;i--,j--)
        {
            if(visited[i][j]==1)
            {
                return false;
            }
        }
        for(int i=row,j=col;i<n&&j>=0;i++,j--)
        {
            if(visited[i][j]==1)
            {
                return false;
            }
        }
        return true;
    }
    void dfs(int j,int n)
    {
        if(j==n)
        {
            ans++;
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(valid(i,j,n))
            {
                visited[i][j]=1;
                dfs(j+1,n);
                visited[i][j]=0;
            }
        }
    }
    int totalNQueens(int n) {
        dfs(0,n);
        return ans;
    }
};