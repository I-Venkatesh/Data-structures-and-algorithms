class Solution {
public:
    int arr[366];
    int dp[366];
    int solve(vector<int>& costs,int day)
    {
        if(day>365)
        {
            return 0;
        }
        if(dp[day]!=-1)
        {
            return dp[day];
        }
        if(arr[day]==0)
        {
            return dp[day]=solve(costs,day+1);
        }
        else{
            return dp[day]=min(costs[0]+solve(costs,day+1),min(costs[1]+solve(costs,day+7),costs[2]+solve(costs,day+30)));
        }
        return dp[day];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(arr,0,sizeof(arr));
        for(int i=0;i<days.size();i++)
        {
            arr[days[i]]++;
        }
        memset(dp,-1,sizeof(dp));
        return solve(costs,1);
    }
};