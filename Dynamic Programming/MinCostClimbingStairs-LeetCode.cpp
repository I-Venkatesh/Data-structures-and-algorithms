class Solution {
public:
    int dp[100005];
    int calc(vector<int> &cost,int curr)
    {
        if(curr>cost.size()-1)
        {
            return 0;
        }
        if(dp[curr]!=-1)
        {
            return dp[curr];
        }
        int stepOne=cost[curr]+calc(cost,curr+1);
        int stepTwo=cost[curr]+calc(cost,curr+2);
        return dp[curr]=min(stepOne,stepTwo);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        int ans=calc(cost,0);
        memset(dp,-1,sizeof(dp));
        int ans2=calc(cost,1);
        return min(ans,ans2);
    }
};