class Solution {
public:
    int dp[201][201];
    int solve(vector<int>& locations, int curr, int finish, int fuel)
    {
        int ans=0;
        if(curr==finish)
        {
            ans+=1;
        }
        if(dp[curr][fuel]!=-1)
        {
            return dp[curr][fuel];
        }
        for(int i=0;i<locations.size();i++)
        {
            if(i==curr)
            {
                continue;
            }
            int hold=abs(locations[curr]-locations[i]);
            if(hold>fuel)
            {
                continue;
            }
            ans=(ans+solve(locations,i,finish,fuel-hold))%1000000007;
        }
        return dp[curr][fuel]=ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(locations,start,finish,fuel);
    }
};