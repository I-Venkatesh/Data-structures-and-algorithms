class Solution {
public:
    int dp[1001][1001];
    int calc(vector<vector<int>>& grid,int i,int j)
    {
        int ans=0;
        if(i>=grid.size())
        { 
            return j;
        }
        else if(j<0||j>=grid[0].size())
        {
            return -1;
        }
        else if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        else if(j==0)
        {
            if(i==0)
            {
                if(grid[i][j]==-1||(grid[i][j]==1&&grid[i][j+1]==-1))
                {   
                    return -1;
                }
            }
            else if(grid[i][j+1]==-1&&grid[i][j]==1)
            {
                return -1;
            }
            ans=calc(grid,i+1,j+1);
        }
        else if(j==grid[0].size()-1)
        {
            if(i==0)
            {
                if(grid[i][j]==1||(grid[i][j]==-1&&grid[i][j-1]==1))
                {
                    return -1;
                }
            }
            else if(grid[i][j]==-1&&grid[i][j-1]==1)
            {
                return -1;
            }
            ans=calc(grid,i+1,j-1);
        }
        else if((grid[i][j]==1&&grid[i][j+1]==-1)||(grid[i][j]==-1&&grid[i][j-1]==1))
        {            
            return -1;
        }
        else if(grid[i][j]==1)
        {
            ans=calc(grid,i+1,j+1);
        }
        else if(grid[i][j]==-1)
        {
            ans=calc(grid,i+1,j-1);
        }
        return dp[i][j]=ans;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        if(grid[0].size()==1)
        {
            ans.push_back(-1);
            return ans;
        }
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<grid[0].size();i++)
        {
            int x=calc(grid,0,i);
            ans.push_back(x);
        }
        return ans;
    }
}; 