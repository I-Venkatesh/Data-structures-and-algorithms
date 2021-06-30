class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int visited[m][n];
        memset(visited,0,sizeof(visited));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0&&visited[i][j]==0)
                {
                    visited[i][j]=1;
                    for(int k=0;k<n;k++)
                    {
                        if(matrix[i][k]!=0)
                        {
                            matrix[i][k]=0;
                            visited[i][k]=1;
                        }
                    }
                    for(int k=0;k<m;k++)
                    {
                        if(matrix[k][j]!=0)
                        {
                            matrix[k][j]=0;
                            visited[k][j]=1;
                        }
                    } 
                }
            }
        }
    }
};