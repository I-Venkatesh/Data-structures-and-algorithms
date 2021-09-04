class Solution {
public:
    int dp[1001][201];
    int solve(vector<int>& nums, int target,int curr)
    {
       
        if(curr==nums.size()||target<0)
        {
            return 0;
        }
        if(dp[target][curr]!=-1)
        {
            return dp[target][curr];
        }
        if(target==0)
        {
            return 1;
        }
        return dp[target][curr]=solve(nums,target-nums[curr],0)+solve(nums,target,curr+1);
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,target,0);
    }
};