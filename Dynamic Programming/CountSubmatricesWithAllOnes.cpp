class Solution {
public:
    int dp[151][151];
    int numSubmat(vector<vector<int>>& mat) 
    {    
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(i==0)
                {
                    if(mat[i][j])
                    {
                        dp[i][j]=mat[i][j];
                    }
                }
                else{
                    if(mat[i][j])
                    {
                        dp[i][j]=dp[i-1][j]+1;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j])
                {
                    int mn=dp[i][j];
                    for(int k=j;k>=0;k--)
                    {
                        if(dp[i][k])
                        {
                            mn=min(mn,dp[i][k]);
                            ans+=mn;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
    
};