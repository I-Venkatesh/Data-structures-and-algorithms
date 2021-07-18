class Solution {
public:
    char arr[10][10];
    bool check(int row,int col,int num)
    {
        int i, j;
        for (i = 0; i < col; i++)
            if (arr[row][i]=='Q')
                return false;
        for (i=row, j=col; i>=0 && j>=0; i--, j--)
            if (arr[i][j]=='Q')
                return false;
        for (i=row, j=col; j>=0 && i<num; i++, j--)
            if (arr[i][j]=='Q')
                return false;
        return true;
    }
    vector<vector<string>> ans;
    void dfs(int n,int j)
    {
        if(j==n)
        {
            vector<string> t;
            for(int u=0;u<n;u++)
            {
                string x;
                for(int v=0;v<n;v++)
                {
                    x+=arr[u][v];
                }
                t.push_back(x);
            }
            ans.push_back(t);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(check(i,j,n))
            {
                arr[i][j]='Q';
                dfs(n,j+1);
                arr[i][j]='.';
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                arr[i][j]='.';
            }
        }
        dfs(n,0);
        return ans;
    }
};