class Solution {
public:
    int dp[101][101];
    int solve(vector<vector<int>>& costs,int a,int curr)
    {
        if(curr==costs.size()&&a==costs.size()/2)
        {
            return 0;
        }
        if(curr==costs.size()&&a!=costs.size()/2)
        {
            return 1000000;
        }
        if(dp[a][curr]!=-1)
        {
            return dp[a][curr];
        }
        int first=min(costs[curr][0]+solve(costs,a+1,curr+1),costs[curr][1]+solve(costs,a,curr+1));
        return dp[a][curr]=first;
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        memset(dp,-1,sizeof(dp));
        return solve(costs,0,0);
    }
};