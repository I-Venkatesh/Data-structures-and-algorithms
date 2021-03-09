class Solution {
public:
    int valid(int i,int j,vector<vector<int>>& matrix,int s)
    {
        int m=matrix.size(),n=matrix[0].size();
        if(i<m&&i>=0&&j<n&&j>=0&&matrix[i][j]==s)
        {
            return 1;
        }
        return 0;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int ans=0;
        vector<vector<int>> prevMatrix=matrix;
        for(int s=1;s<=min(m,n);s++)
        {
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(s==1)
                    {
                        if(prevMatrix[i][j]==1)
                        {
                            ans++;
                        }
                    }
                    else{
                        if(prevMatrix[i][j]==s-1)
                        {
                            if(valid(i-1,j,prevMatrix,s-1)&&valid(i-1,j-1,prevMatrix,s-1)&&valid(i,j-1,prevMatrix,s-1))
                            {
                                matrix[i][j]=s;
                                ans++;
                            }
                        }
                    }
                }
            }
            prevMatrix=matrix;
        }
        return ans;
    }
};