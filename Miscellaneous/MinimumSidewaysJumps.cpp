class Solution {
public:
    int dp[500001][4];
    int solve(vector<int>& obs,int curr,int lane)
    {
        if(curr+1>=obs.size())
        {
            return 0;
        }
        if(dp[curr][lane]!=-1)
        {
            return dp[curr][lane];
        }
        int ans=1000000;
        if(curr+1<obs.size()&&obs[curr+1]!=lane)
        {
            ans=min(ans,solve(obs,curr+1,lane));
        }
        else{
            if(curr+1<obs.size()&&obs[curr+1]!=1&&lane!=1&&obs[curr]!=1)
            {
                ans=min(ans,1+solve(obs,curr+1,1));
            }
            if(curr+1<obs.size()&&obs[curr+1]!=2&&lane!=2&&obs[curr]!=2)
            {
                ans=min(ans,1+solve(obs,curr+1,2));
            }
            if(curr+1<obs.size()&&obs[curr+1]!=3&&lane!=3&&obs[curr]!=3)
            {
                ans=min(ans,1+solve(obs,curr+1,3));
            }
        }
        return dp[curr][lane]=ans;
    }
    int minSideJumps(vector<int>& obstacles) {
        memset(dp,-1,sizeof(dp));
        return solve(obstacles,0,2);
    }
};